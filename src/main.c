// main.c
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main);

void hello_printk_thread(void *p1, void *p2, void *p3)
{
	while (1) {
		printk("Hello World from printk!\n");
		k_msleep(2000); // Print every 2 seconds
	}
}

void hello_logging_thread(void *p1, void *p2, void *p3)
{
	while (1) {
		LOG_INF("Hello World from logging module!");
		k_msleep(3000); // Log every 3 seconds
	}
}

K_THREAD_DEFINE(hello_printk_thread_id, 512, hello_printk_thread, NULL, NULL, NULL,
		7, 0, 0);

K_THREAD_DEFINE(hello_logging_thread_id, 512, hello_logging_thread, NULL, NULL, NULL,
		7, 0, 0);

int main(void)
{
	LOG_INF("Main thread started.");
	return 0;
}