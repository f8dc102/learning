#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 20
#define MAX_CITIES 2 
#define PRICE_PER_SEAT 20000
#define DUMMY_VALUE 0

/*
 * Function Declarations
 */
void printStatus(); void reserveSeat();
void changeSeat(); void cancelSeat();

int getLocNumber(const char *city);

/*
 * Constant Values
 */
const char *cityList[MAX_CITIES] = {"SEOUL", "BUSAN"};
int seatInfo[MAX_CITIES][MAX_SEATS] = {0};

/*
 * Function Definitions
 */
int main() {
    int userChoice = 0;

    printf("<고속버스>\n");
    printf("무엇을 도와드릴까요?\n");
    printf("1. 버스표 상태\n");
    printf("2. 버스표 예매\n");
    printf("3. 버스표 변경\n");
    printf("4. 버스표 취소\n");
    printf("5. 종료\n");

    printf("\n번호를 입력하세요: "); scanf("%d", &userChoice);

    switch (userChoice) {
        case 1: printStatus(); break;
        case 2: reserveSeat(); break;
        case 3: changeSeat(); break;
        case 4: cancelSeat(); break;
        case 5: printf("고속버스를 이용해주셔서 감사합니다.\n"); break;
        default: printf("잘못된 입력입니다.\n"); return 1;
    }

    return 0;
}

int getLocNumber(const char *city) {
    int locNumber = 0;

    for (int i = 0; i < 2; i++) {
        if (strcmp(city, cityList[i]) == 0) return i;
    }

    return -1;
}

int commonPrompt(char printMode, int busNumber) {
    if (printMode == 'l') {
        printf("\n");

        int pcUserChoice = 0;

        for (int i = 0; i < MAX_CITIES; i++) {
            printf("%d. %s ", i + 1, cityList[i]);
        }

        printf("\n\n");
        printf("어떤 버스를 보시겠습니까? => "); scanf("%d", &pcUserChoice);

        if (pcUserChoice < 1 || pcUserChoice > MAX_CITIES) {
            printf("잘못된 입력입니다.\n");
            return -1;
        }

        return pcUserChoice;
    } 

    if (printMode == 'd' && busNumber != DUMMY_VALUE) {
        FILE *fp = fopen("server.txt", "r");
        char city[21];

        // Get Destination City
        for (int i = 0; i < 5; i++) {
            fscanf(fp, "%s", city);

            if (i == busNumber - 1) {
                printf("도착지: %s\n", city);
                printf("요금: %d\n", PRICE_PER_SEAT);
                printf("좌석: \n");
                break;
            }
        }
    }

    if (printMode == 's' && busNumber != DUMMY_VALUE) {
        FILE *fp = fopen("server.txt", "r"); 
        char city[21];
        int seat = 0;

        // Put file information into array
        for (int i = 0; i < 5; i++) {
            for (int k = 0; k < 4; k++) {
                fscanf(fp, "%s %d", city, &seat);
                int locNumber = getLocNumber(city);

                if (locNumber == busNumber - 1) {
                    seatInfo[locNumber][seat - 1] = 1;
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int k = 0; k < 4; k++) {
                if (k == 0 || k == 2) printf("%2d ", 6 + (i - 1) * 4 + k - 1);

                if (seatInfo[i][(i - 1) * 4 + k] == 0) printf("■ ");
                else printf("□ ");

                if (k == 3) printf(" ");
            }

            printf("\n");
        }

        printf("\n");
    }

    return 0;
}

void printStatus() {
    printf("\n1 / 버스표 상태");

    int busNumber = commonPrompt('l', DUMMY_VALUE);
    printf("\n");

    commonPrompt('d', busNumber);
    commonPrompt('s', busNumber);

    int tmp;
    printf("계속하려면 아무 키나 누르십시오..."); 
    scanf("%d", &tmp); main();
}

void reserveSeat() {
    
}

void changeSeat() {
    
}

void cancelSeat() {
    
}
