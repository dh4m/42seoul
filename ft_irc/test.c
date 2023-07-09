/* Kernel Queue The Complete Guide: kqueue-user.c: User-triggered events */
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/event.h>
#include <fcntl.h>

int kq;
char str[10];

struct context {
	void (*handler)(struct context *obj);
};

struct context user_event_obj;

void user_event_obj_handler(struct context *obj)
{
	printf("Received user event via kqueue\n");
}

// application calls this function whenever it wants to add a new event to KQ
// which will execute user_event_obj_handler()
void trigger_user_event()
{
	user_event_obj.handler = user_event_obj_handler;

	struct kevent events[1];
	EV_SET(&events[0], 1234, EVFILT_USER, 0, NOTE_TRIGGER, 0, &user_event_obj);
	assert(0 == kevent(kq, events, 1, NULL, 0, NULL));
}

void main()
{
	// create kqueue object
	kq = kqueue();
	assert(kq != -1);

	// register user event with any random ID
	// note that user data is NULL here
	struct kevent events[1];
	EV_SET(&events[0], 1234, EVFILT_USER, EV_ADD | EV_ENABLE | EV_CLEAR, 0, 0, NULL);
	assert(0 == kevent(kq, events, 1, NULL, 0, NULL));
	EV_SET(&events[0], STDIN_FILENO, EVFILT_READ, EV_ADD | EV_ENABLE | EV_CLEAR, 0, 0, NULL);
	assert(0 == kevent(kq, events, 1, NULL, 0, NULL));

	//trigger_user_event();
	//trigger_user_event();
	//trigger_user_event();
	//trigger_user_event();

	struct timespec *timeout = NULL; // wait indefinitely
	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
	while (1)
	{
		int n = kevent(kq, NULL, 0, events, 1, timeout);
		printf("%d\n", n);
		assert(n > 0);

		struct context *o = events[0].udata;
		if (events[0].filter == EVFILT_USER)
			o->handler(o); // handle user event
		else if (events[0].filter == EVFILT_READ)
		{
			printf("read accept\n");
			str[read(0, str, 10)] = 0;
			
			printf("###: %s\n", str);
		}
		// trigger_user_event();
	}

	close(kq);
}