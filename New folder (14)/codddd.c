#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdint.h>

struct Pair{
	int Id;
	uint64_t Start, End;
};

const uint64_t LARGE_NUMBER = UINT32_MAX;
volatile uint64_t g_Sum = 0;
pthread_mutex_t lock;

void Adder(uint64_t start, uint64_t end) {
	uint64_t sum = 0;
	for(uint64_t i = start;i < end; i++)
	{
		sum += i;
	}
	pthread_mutex_lock(&lock);
	g_Sum += sum;
	pthread_mutex_unlock(&lock);
}

void *AdderThreadEntry(void *arg) {
	auto pair = (Paisr *)arg;
	printf("Thread %d started\n", pair->Id);
	Adder(pair->Start, pair->End);
	printf("Thread %d ended\n", pair->Id);
	return nullptr;
}

#define THREAD_COUNT 12

int main(int argc, char **argv) {
	pthread_mutex_init(&lock, nullptr);
	pthread_t thread[THREAD_COUNT];
	Pair pair[THREAD_COUNT];
	uint64_t split = LARGE_NUMBER / THREAD_COUNT;
	for (int i = 0; i < THREAD_COUNT; ++i) {
		pair[i] = Pair{i, i * split, (i + 1) * split};
		pthread_create(&thread[i], nullptr, AdderThreadEntry, &pair[i]);
	}
	for (int i = 0; i < THREAD_COUNT; ++i) {
		pthread_join(thread[i], nullptr);
	}
	printf("Sum from 1 to %zu = %zu\n", LARGE_NUMBER, g_Sum);
	return 0;
}
