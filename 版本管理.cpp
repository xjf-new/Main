#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100

// ��������/֧����¼�ṹ��
typedef struct {
    char date[11];
    double amount;
    char category[20];
    char note[50];
} Record;

// �����˵��ṹ��
typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Bill;

// ��ʼ���˵�
void initBill(Bill *bill) {
    bill->count = 0;
}

// ��Ӽ�¼�������֧����
void addRecord(Bill *bill, char date[], double amount, char category[], char note[]) {
    if (bill->count >= MAX_RECORDS) {
        printf("�˵���¼������\n");
        return;
    }
    strcpy(bill->records[bill->count].date, date);
    bill->records[bill->count].amount = amount;
    strcpy(bill->records[bill->count].category, category);
    strcpy(bill->records[bill->count].note, note);
    bill->count++;
}

// ��¼����
void recordIncome(Bill *bill) {
    char date[11];
    double amount;
    char category[20];
    char note[50];

    printf("�������������ڣ���ʽ��YYYY - MM - DD����");
    scanf("%s", date);
    printf("�����������");
    scanf("%lf", &amount);
    while (amount <= 0) {
        printf("���������Ϊ���������������룺");
        scanf("%lf", &amount);
    }
    printf("�������������");
    scanf("%s", category);
    printf("�����뱸ע��");
    scanf("%s", note);

    addRecord(bill, date, amount, category, note);
    printf("�����¼����ӣ�\n");
}

// ��¼֧��
void recordExpense(Bill *bill) {
    char date[11];
    double amount;
    char category[20];
    char note[50];

    printf("������֧�����ڣ���ʽ��YYYY - MM - DD����");
    scanf("%s", date);
    printf("������֧����");
    scanf("%lf", &amount);
    while (amount <= 0) {
        printf("֧��������Ϊ���������������룺");
        scanf("%lf", &amount);
    }
    printf("������֧�����");
    scanf("%s", category);
    printf("�����뱸ע��");
    scanf("%s", note);

    addRecord(bill, date, amount, category, note);
    printf("֧����¼����ӣ�\n");
}

// չʾ�����˵���¼�������֧���ֿ���ʾ��
void displayBills(Bill *bill) {
    printf("\n�����¼��\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount > 0) {
            printf("���ڣ�%s����%.2f�����%s����ע��%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
    printf("\n֧����¼��\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount < 0) {
            printf("���ڣ�%s����%.2f�����%s����ע��%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
}

// ����ָ�����ڲ�ѯ�˵��������֧���ֿ���ʾ��
void queryBillsByDate(Bill *bill, char queryDate[]) {
    printf("\n�����¼��\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount > 0 && strcmp(bill->records[i].date, queryDate) == 0) {
            printf("���ڣ�%s����%.2f�����%s����ע��%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
    printf("\n֧����¼��\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount < 0 && strcmp(bill->records[i].date, queryDate) == 0) {
            printf("���ڣ�%s����%.2f�����%s����ע��%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
}

// �������ڷ�Χ��ѯ�˵��������֧���ֿ���ʾ��
void queryBillsByDateRange(Bill *bill, char startDate[], char endDate[]) {
    printf("\n�����¼��\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount > 0 &&
            strcmp(bill->records[i].date, startDate) >= 0 &&
            strcmp(bill->records[i].date, endDate) <= 0) {
            printf("���ڣ�%s����%.2f�����%s����ע��%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
    printf("\n֧����¼��\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount < 0 &&
            strcmp(bill->records[i].date, startDate) >= 0 &&
            strcmp(bill->records[i].date, endDate) <= 0) {
            printf("���ڣ�%s����%.2f�����%s����ע��%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
}

// ��������ѯ�˵��������֧���ֿ���ʾ��
void queryBillsByCategory(Bill *bill, char queryCategory[]) {
    printf("\n�����¼��\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount > 0 && strcmp(bill->records[i].category, queryCategory) == 0) {
            printf("���ڣ�%s����%.2f�����%s����ע��%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
    printf("\n֧����¼��\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount < 0 && strcmp(bill->records[i].category, queryCategory) == 0) {
            printf("���ڣ�%s����%.2f�����%s����ע��%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
}

// Ԥ�����
void budgetManagement() {
    double budget;
    printf("������ÿ��֧��Ԥ���޶");
    scanf("%lf", &budget);

    // ��ȡ��ǰ�·�
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int currentMonth = tm->tm_mon + 1;
    double currentExpense = 0;

    Bill bill;
    initBill(&bill);
    // ����������ļ�����������Դ�����˵����ݵ�bill�ṹ����
    // Ϊ�˼򻯣�����û��ʵ�����ݼ��ع���

    for (int i = 0; i < bill.count; i++) {
        char monthStr[3];
        strncpy(monthStr, bill.records[i].date + 5, 2);
        monthStr[2] = '\0';
        int month = atoi(monthStr);
        if (month == currentMonth && bill.records[i].amount < 0) {
            currentExpense += (-1) * bill.records[i].amount;
        }
    }

    double remainingBudget = budget - currentExpense;
    printf("��ǰʣ�����Ԥ�㣺%.2f\n", remainingBudget);
}

// �¶�ͳ��
void monthlyStatistics() {
    // ��ȡ��ǰ�·�
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int currentMonth = tm->tm_mon + 1;

    Bill bill;
    initBill(&bill);
    // ����������ļ�����������Դ�����˵����ݵ�bill�ṹ����
    // Ϊ�˼򻯣�����û��ʵ�����ݼ��ع���

    double totalIncome = 0;
    double totalExpense = 0;
    double categoryAmount[20] = {0}; // �������20����𣬿ɸ�����Ҫ����

    for (int i = 0; i < bill.count; i++) {
        char monthStr[3];
        strncpy(monthStr, bill.records[i].date + 5, 2);
        monthStr[2] = '\0';
        int month = atoi(monthStr);
        if (month == currentMonth) {
            if (bill.records[i].amount > 0) {
                totalIncome += bill.records[i].amount;
            } else {
                totalExpense += (-1) * bill.records[i].amount;
            }
            for (int j = 0; j < 20; j++) {
                if (strcmp(bill.records[i].category, "") == 0) continue;
                if (strcmp(bill.records[i].category, "") == 0) break;
                if (strcmp(bill.records[i].category, "") == 0) {
                    categoryAmount[j] += (-1) * bill.records[i].amount;
                }
            }
        }
    }

    printf("���������룺%.2f\n", totalIncome);
    printf("������֧����%.2f\n", totalExpense);
    printf("�����֧����\n");
    for (int j = 0; j < 20; j++) {
        if (categoryAmount[j] > 0) {
            printf("%s: %.2f\n", bill.records[j].category, categoryAmount[j]);
        }
    }
}

int main() {
    Bill bill;
    initBill(&bill);
    int choice;

    do {
        printf("\n�����˵�����ϵͳ\n");
        printf("1. ��¼����\n");
        printf("2. ��¼֧��\n");
        printf("3. չʾ�˵�\n");
        printf("4. �����ڲ�ѯ�˵�\n");
        printf("5. �����ڷ�Χ��ѯ�˵�\n");
        printf("6. ������ѯ�˵�\n");
        printf("7. Ԥ�����\n");
        printf("8. �¶�ͳ��\n");
        printf("0. �˳�\n");
        printf("��ѡ�������");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                recordIncome(&bill);
                break;
            case 2:
                recordExpense(&bill);
                break;
            case 3:
                displayBills(&bill);
                break;
            case 4: {
                char queryDate[11];
                printf("�������ѯ���ڣ���ʽ��YYYY - MM - DD����");
                scanf("%s", queryDate);
                queryBillsByDate(&bill, queryDate);
                break;
            }
            case 5: {
                char startDate[11];
                char endDate[11];
                printf("�����뿪ʼ���ڣ���ʽ��YYYY - MM - DD����");
                scanf("%s", startDate);
                printf("������������ڣ���ʽ��YYYY - MM - DD����");
                scanf("%s", endDate);
                queryBillsByDateRange(&bill, startDate, endDate);
                break;
            }
            case 6: {
                char queryCategory[20];
                printf("�������ѯ���");
                scanf("%s", queryCategory);
                queryBillsByCategory(&bill, queryCategory);
                break;
            }
            case 7:
                budgetManagement();
                break;
            case 8:
                monthlyStatistics();
                break;
            case 0:
                printf("�˳�ϵͳ��\n");
                break;
            default:
                printf("��Чѡ��������ѡ��\n");
        }
    } while (choice!= 0);

    return 0;
}
