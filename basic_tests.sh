#!/bin/bash

echo "STARTING TESTS\n"
sleep 1
echo "\nTest 1:\n"
echo "1 Philosopher\n"
echo "Time to die 800ms\n"
echo "Time to eat 200ms\n"
echo "Time to sleep 200ms\n"
./philo 1 800 200 200
sleep 1
echo "\nTest 2:\n"
echo "5 Philosophers\n"
echo "Time to die 800ms\n"
echo "Time to eat 200ms\n"
echo "Time to sleep 200ms\n"
while ./philo 5 800 200 200; do sleep 10; done
sleep 1
echo "\nTest 3:\n"
echo "5 Philosophers\n"
echo "Time to die 800ms\n"
echo "Time to eat 200ms\n"
echo "Time to sleep 200ms\n"
echo "Number of meals 7\n"
./philo 5 800 200 200 7
sleep 1
echo "\nTest 4:\n"
echo "4 Philosophers\n"
echo "Time to die 410ms\n"
echo "Time to eat 200ms\n"
echo "Time to sleep 200ms\n"
while ./philo 4 410 200 200; do sleep 10; done
sleep 1
echo "\nTest 5:\n"
echo "4 Philosophers\n"
echo "Time to die 310ms\n"
echo "Time to eat 200ms\n"
echo "Time to sleep 100ms\n"
./philo 4 310 200 100
sleep 1
echo "\nTest 6:\n"
echo "2 Philosophers\n"
echo "Time to die 800ms\n"
echo "Time to eat 200ms\n"
echo "Time to sleep 200ms\n"
while ./philo 2 800 200 200; do sleep 10; done
