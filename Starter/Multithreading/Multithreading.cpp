#include <iostream>
#include <thread>
#include <chrono> //Zeitfunktionen fuer sleep -Angaben
#include <mutex>
#include <atomic>
#include <future>

std::mutex mutex1;
std::mutex mutex2;
std::mutex mutex3;

std::timed_mutex tMutex1;

void printNumbers(int max, std::string name)
{
	for (size_t i = 0; i < max; i++)
	{
		mutex1.lock();
		std::cout << name << ": " << i << std::endl;
		mutex1.unlock();

		// Auf Thread zugreifen:
		// Rechenleistung freigeben:
		//std::this_thread::yield; //Andere Prozesse sollen abgearbeitet werden

		//Thread schlafen schicken (Zeitangabe nur ungefaehr):
		std::this_thread::sleep_for(std::chrono::nanoseconds(1));

	}
}

void printNumbers2(int max, std::string name)
{
	for (size_t i = 0; i < max; i++)
	{
		if (std::try_lock(mutex1, mutex2, mutex3) == -1)
		{
			std::cout << name << ": " << i << std::endl;
			mutex1.unlock();
			mutex2.unlock();
			mutex3.unlock();
		}
		std::this_thread::sleep_for(std::chrono::nanoseconds(1));
	}
}

void printNumbers3(int max, std::string name)
{
	for (size_t i = 0; i < max; i++)
	{
		if (tMutex1.try_lock_for(std::chrono::seconds(1)))
		{
			std::cout << name << ": " << i << std::endl;
			tMutex1.unlock();

		}
		std::this_thread::sleep_for(std::chrono::nanoseconds(1));
	}
}

//Atomic: Bestimmte prozessor-interne Optimierungen fallen weg
//std::atomic<bool> stop = false;
bool stop = false;
void process() 
{
	int x = 0;
	while (!stop)
	{
		x++; // Mutex nicht noetig, da nur 1xSchreiben (sobald mehr (z.b. if) wird Mutex benoetigt)
	}
}

// Future:
int doCalculation()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return 27;
}

//Promise:
void present(std::future<float> future)
{
	//Abfragen ob Future fertig ist:
	if (future.wait_for(std::chrono::nanoseconds(0)) == std::future_status::ready)
	{
		// ...fertig
	}
	float result = future.get();
	std::cout << "Presenter: " << result << std::endl;
}

int main()
{
	std::thread processing1(process);
	//std::thread processing2(process);
	//std::thread processing3(process);
	//std::thread processing4(process);
	//std::thread processing5(process);
	//std::thread processing6(process);
	//std::thread processing7(process);
	//std::thread processing8(process);
	//std::thread processing9(process);
	//std::thread processing10(process);
	//std::thread processing11(process);
	//std::thread processing12(process);

	//Thread erstellen:
	std::thread printNumberThread(printNumbers, 100, "Thread1");
	std::thread printNumberThread2(printNumbers2, 100, "Thread2");
	std::thread printNumberThread3(printNumbers3, 100, "Thread3");

	printNumbers(100, "Mein Thread");

	//Warten bis Threads fertig (Am besten immer aufrufen am Ende!):
	printNumberThread.join();
	printNumberThread2.join();
	printNumberThread3.join();

	stop = true;
	processing1.join();

	//Future:
	//Berechnung starten:
	std::future<int> future = std::async(doCalculation);

	//... weiterer code

	//Ergebnis der Berechnung abfragen oder ggf. drauf warten:
	int result = future.get();

	//...weiterer code mit result wert
	std::cout << "Future Result: " << result << std::endl;

	//Promise:
	std::promise<float> promise;
	std::thread presenterThread = std::thread(present, promise.get_future());
	promise.set_value(12.34f);
	presenterThread.join();
	return 0;
}