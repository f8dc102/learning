#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <curses.h>
#include <string.h>

void PrintBusTicketStatus();
void PrintBusTicketReservation();
void PrintBusTicketChange();
void PrintBusTicketCancellation();
void PrintScreen(int mode);
int GetLocationNumber(const char* location);

const char* LocationNames[3] = { "", "SEOUL", "BUSAN" };

int SeatInfo[3][20] = { 0 };



int main()

{

    FILE* fp = fopen("server.txt", "r");



    char temp;

    int isLocation = 1;

    char location[10];

    int countChar = 0;

    int newLineCount = 0;



    while ((temp = fgetc(fp)) != EOF)

    {

        if (temp == ' ')

        {

            location[countChar] = '\0';

            countChar = 0;

            isLocation = 0;

        }

        else if (temp == '\n')

        {

            SeatInfo[GetLocationNumber(location)][countChar] = 1;

            countChar = 0;

            isLocation = 1;



            if (newLineCount == 1)

                break;

            else

                newLineCount++;

        }

        else

        {

            if (isLocation == 1)

            {

                location[countChar] = temp;

                countChar++;

            }

            else

            {

                if (countChar == 0)

                    countChar = temp - '0';

                else

                    countChar = countChar * 10 + (temp - '0');

            }

            newLineCount = 0;

        }

    }



    int userChoice;



    printf("<고속버스>\n");

    printf("무엇을 도와드릴까요?\n");

    printf("1. 버스표 상태\n");

    printf("2. 버스표 예매\n");

    printf("3. 버스표 변경\n");

    printf("4. 버스표 취소\n");

    printf("5. 종료\n");



    userChoice = _getch() - '0';

    while (userChoice <= 0 || userChoice >= 6)

    {

        printf("잘못된 입력입니다. 다시 입력해주세요.\n");

        userChoice = _getch() - '0';

    }



    switch (userChoice)

    {

    case 1:

        PrintBusTicketStatus();

        break;

    case 2:

        PrintBusTicketReservation();

        break;

    case 3:

        PrintBusTicketChange();

        break;

    case 4:

        PrintBusTicketCancellation();

        break;

    case 5:

        printf("프로그램을 종료합니다.\n");

        break;

    }



    return 0;

}



void PrintBusTicketStatus()

{

    PrintScreen(1);

}



void PrintBusTicketReservation()

{

    PrintScreen(1);



    printf("예매할 버스를 선택해주세요: ");

    int busNumber = _getch() - '0';

    while (busNumber <= 0 || busNumber >= 3)

    {

        printf("잘못된 입력입니다. 다시 입력해주세요.\n");

        busNumber = _getch() - '0';

    }



    printf("예매할 좌석을 선택해주세요 (예: 1a): ");

    char seatInput[3];

    scanf("%s", seatInput);



    int row = seatInput[0] - '0';

    char column = seatInput[1];

    int seatIndex = (row - 1) * 4 + (column - 'a');



    if (SeatInfo[busNumber][seatIndex] == 1)

    {

        printf("이미 예매된 좌석입니다.\n");

        return;

    }



    SeatInfo[busNumber][seatIndex] = 1;



    printf("예매가 완료되었습니다!\n");

}



void PrintBusTicketChange()

{

    PrintScreen(1);



    printf("변경할 버스를 선택해주세요: ");

    int busNumber = _getch() - '0';

    while (busNumber <= 0 || busNumber >= 3)

    {

        printf("잘못된 입력입니다. 다시 입력해주세요.\n");

        busNumber = _getch() - '0';

    }



    printf("현재 예매된 좌석: \n");

    for (int i = 1; i <= 5; i++)

    {

        for (int k = 1; k <= 4; k++)

        {

            int seatIndex = (i - 1) * 4 + (k - 1);

            if (SeatInfo[busNumber][seatIndex] == 1)

                printf("%d%c ", i, 'a' + (k - 1));

        }

    }

    printf("\n");



    printf("변경할 좌석을 선택해주세요 (예: 1a): ");

    char seatInput[3];

    scanf("%s", seatInput);



    int row = seatInput[0] - '0';

    char column = seatInput[1];

    int seatIndex = (row - 1) * 4 + (column - 'a');



    if (SeatInfo[busNumber][seatIndex] == 1)

    {

        printf("이미 예매된 좌석입니다.\n");

        return;

    }



    printf("변경이 완료되었습니다!\n");



    // 기존 좌석 취소

    for (int i = 1; i <= 5; i++)

    {

        for (int k = 1; k <= 4; k++)

        {

            int seatIndex = (i - 1) * 4 + (k - 1);

            if (SeatInfo[busNumber][seatIndex] == 1)

                SeatInfo[busNumber][seatIndex] = 0;

        }

    }



    // 새로운 좌석 예매

    SeatInfo[busNumber][seatIndex] = 1;

}



void PrintBusTicketCancellation()

{

    PrintScreen(1);



    printf("취소할 버스를 선택해주세요: ");

    int busNumber = _getch() - '0';

    while (busNumber <= 0 || busNumber >= 3)

    {

        printf("잘못된 입력입니다. 다시 입력해주세요.\n");

        busNumber = _getch() - '0';

    }



    printf("현재 예매된 좌석: \n");

    for (int i = 1; i <= 5; i++)

    {

        for (int k = 1; k <= 4; k++)

        {

            int seatIndex = (i - 1) * 4 + (k - 1);

            if (SeatInfo[busNumber][seatIndex] == 1)

                printf("%d%c ", i, 'a' + (k - 1));

        }

    }

    printf("\n");



    printf("취소할 좌석을 선택해주세요 (예: 1a): ");

    char seatInput[3];

    scanf("%s", seatInput);



    int row = seatInput[0] - '0';

    char column = seatInput[1];

    int seatIndex = (row - 1) * 4 + (column - 'a');



    if (SeatInfo[busNumber][seatIndex] == 0)

    {

        printf("선택한 좌석은 예매되지 않았습니다.\n");

        return;

    }



    SeatInfo[busNumber][seatIndex] = 0;



    printf("취소가 완료되었습니다!\n");

}



void PrintScreen(int mode)

{

    printf("\n버스를 선택해주세요\n");

    printf("1. 서울\n");

    printf("2. 부산\n\n");



    int busNumber = _getch() - '0';

    while (busNumber <= 0 || busNumber >= 3)

    {

        printf("잘못된 입력입니다. 다시 입력해주세요.\n");

        busNumber = _getch() - '0';

    }



    printf("도착지: %s\n", LocationNames[busNumber]);

    printf("요금: 20000\n\n");



    printf("<좌석>\n");

    printf(" a b  c d\n");

    for (int i = 1; i <= 5; i++)

    {

        printf("%d", i);

        for (int k = 1; k <= 4; k++)

        {

            if (SeatInfo[busNumber][(i - 1) * 4 + k - 1] == 1)

                printf("■");

            else

                printf("□");



            if (k == 2)

                printf(" ");

        }

        printf("\n");

    }

}



int GetLocationNumber(const char* location)

{

    int locationNumber = 0;

    for (int i = 1; i <= 2; i++)

    {

        if (strcmp(location, LocationNames[i]) == 0)

        {

            locationNumber = i;

            break;

        }

    }

    return locationNumber;

}


