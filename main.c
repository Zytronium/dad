#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int t = 1;

void println(const char *msg, ...) {
	va_list arg;

	va_start (arg, msg);
	vfprintf (stdout, msg, arg);
	putchar('\n');
	va_end (arg);
}

char *timeElapsed() {
	int tm = t;
	int hrs = 0;
	int dys = 0;
	int wks = 0;
	int mnths = 0;
	int yrs = 0;

	while (tm > 0) {
		if (tm >= 8760) {
			tm -= 8760;
			yrs++;
		} else if (tm >= 730) {
			tm -= 730;
			mnths++;
		} else if (tm >= 168) {
			tm -= 168;
			wks++;
		} else if (tm >= 24) {
			tm -= 24;
			dys++;
		} else if (tm < 24) {
			hrs = tm;
			tm = 0;
		}
	}

	char* result = malloc(64);
	char yearsStr[13];
	char monthsStr[12];
	char weeksStr[10];
	char daysStr[9];
	char hoursStr[9];

	if (yrs != 0) {
		sprintf(yearsStr, (yrs == 1) ? "1 year, " : "%d years, ", yrs);
	} else {
		yearsStr[0] = '\0';
	}

	if (mnths != 0) {
		sprintf(monthsStr, (mnths == 1) ? "1 month, " : "%d months, ", mnths);
	} else {
		monthsStr[0] = '\0';
	}

	if (wks != 0) {
		sprintf(weeksStr, (wks == 1) ? "1 week, " : "%d weeks, ", wks);
	} else {
		weeksStr[0] = '\0';
	}

	if (dys != 0) {
		sprintf(daysStr, (dys == 1) ? "1 day, " : "%d days, ", dys);
	} else {
		daysStr[0] = '\0';
	}

	sprintf(hoursStr, (hrs == 1) ? "1 hour" : "%d hours", hrs);

	sprintf(result, "%s%s%s%s%s%s",
			yearsStr,
			monthsStr,
			weeksStr,
			daysStr,
			((yrs != 0 || mnths != 0 || wks != 0 || dys != 0)) ? "and " : "",
			hoursStr
	);

	return result;
}

char *timeElapsedShort() { /* WIP. Low priority, since it'll never be used. */
	return "10 YEARS";
}

void returnWithMilk() {
	println("Dad has left the store and is returning home with the milk.");
	sleep(3);
	printf("Dad: ");
	sleep(1);
	println("\"I'm home! I finally found the milk!\"");
	sleep(1);
	printf("You: ");
	sleep(1);
	printf("\" .");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(2);
	printf(" What? DAD!? ");
	sleep(1);
	println("IT'S BEEN %s! \"", strupr(timeElapsedShort()));
	sleep(3);
	println("\n T H E    E N D ");
	sleep(12);
	scanf("");
}

void dad() {
	char *storeItems[16] = {
			"cookie dough", "book", "bacon", "batteries", "fruit","a new life",
			"a new family", "cheese", "very large cow","expired eggs", "dog toy",
			"nuclear missile", "another toy", "chocolate", "orange juice", "gift cards"
	};

	srand(time(NULL));
	println("Dad is searching for the milk... (time elapsed: %s)", timeElapsed());
	free(timeElapsed());

	t++;
	sleep(2);

	if (strcmp(storeItems[rand() % (sizeof(storeItems) / sizeof(storeItems[0]))], "milk") == 0) {
		println("\nDad has found the milk.\n");
		sleep(2);
		returnWithMilk();
	} else {
		dad();
	}
}

int main(void) {
	println("Dad.exe is running.");
	sleep(2);
	println("Dad has left to get the milk.");
	sleep(1);
	println("Dad will come back when he has found the milk.");
	sleep(2);

	dad();

	return 0;
}
