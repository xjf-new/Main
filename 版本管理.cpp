#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100

// 定义收入/支出记录结构体
typedef struct {
    char date[11];
    double amount;
    char category[20];
    char note[50];
} Record;

// 定义账单结构体
typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Bill;

// 初始化账单
void initBill(Bill *bill) {
    bill->count = 0;
}

// 添加记录（收入或支出）
void addRecord(Bill *bill, char date[], double amount, char category[], char note[]) {
    if (bill->count >= MAX_RECORDS) {
        printf("账单记录已满！\n");
        return;
    }
    strcpy(bill->records[bill->count].date, date);
    bill->records[bill->count].amount = amount;
    strcpy(bill->records[bill->count].category, category);
    strcpy(bill->records[bill->count].note, note);
    bill->count++;
}

// 记录收入
void recordIncome(Bill *bill) {
    char date[11];
    double amount;
    char category[20];
    char note[50];

    printf("请输入收入日期（格式：YYYY - MM - DD）：");
    scanf("%s", date);
    printf("请输入收入金额：");
    scanf("%lf", &amount);
    while (amount <= 0) {
        printf("收入金额必须为正数，请重新输入：");
        scanf("%lf", &amount);
    }
    printf("请输入收入类别：");
    scanf("%s", category);
    printf("请输入备注：");
    scanf("%s", note);

    addRecord(bill, date, amount, category, note);
    printf("收入记录已添加！\n");
}

// 记录支出
void recordExpense(Bill *bill) {
    char date[11];
    double amount;
    char category[20];
    char note[50];

    printf("请输入支出日期（格式：YYYY - MM - DD）：");
    scanf("%s", date);
    printf("请输入支出金额：");
    scanf("%lf", &amount);
    while (amount <= 0) {
        printf("支出金额必须为正数，请重新输入：");
        scanf("%lf", &amount);
    }
    printf("请输入支出类别：");
    scanf("%s", category);
    printf("请输入备注：");
    scanf("%s", note);

    addRecord(bill, date, amount, category, note);
    printf("支出记录已添加！\n");
}

// 展示所有账单记录（收入和支出分开显示）
void displayBills(Bill *bill) {
    printf("\n收入记录：\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount > 0) {
            printf("日期：%s，金额：%.2f，类别：%s，备注：%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
    printf("\n支出记录：\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount < 0) {
            printf("日期：%s，金额：%.2f，类别：%s，备注：%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
}

// 按照指定日期查询账单（收入和支出分开显示）
void queryBillsByDate(Bill *bill, char queryDate[]) {
    printf("\n收入记录：\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount > 0 && strcmp(bill->records[i].date, queryDate) == 0) {
            printf("日期：%s，金额：%.2f，类别：%s，备注：%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
    printf("\n支出记录：\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount < 0 && strcmp(bill->records[i].date, queryDate) == 0) {
            printf("日期：%s，金额：%.2f，类别：%s，备注：%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
}

// 按照日期范围查询账单（收入和支出分开显示）
void queryBillsByDateRange(Bill *bill, char startDate[], char endDate[]) {
    printf("\n收入记录：\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount > 0 &&
            strcmp(bill->records[i].date, startDate) >= 0 &&
            strcmp(bill->records[i].date, endDate) <= 0) {
            printf("日期：%s，金额：%.2f，类别：%s，备注：%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
    printf("\n支出记录：\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount < 0 &&
            strcmp(bill->records[i].date, startDate) >= 0 &&
            strcmp(bill->records[i].date, endDate) <= 0) {
            printf("日期：%s，金额：%.2f，类别：%s，备注：%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
}

// 按照类别查询账单（收入和支出分开显示）
void queryBillsByCategory(Bill *bill, char queryCategory[]) {
    printf("\n收入记录：\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount > 0 && strcmp(bill->records[i].category, queryCategory) == 0) {
            printf("日期：%s，金额：%.2f，类别：%s，备注：%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
    printf("\n支出记录：\n");
    for (int i = 0; i < bill->count; i++) {
        if (bill->records[i].amount < 0 && strcmp(bill->records[i].category, queryCategory) == 0) {
            printf("日期：%s，金额：%.2f，类别：%s，备注：%s\n",
                   bill->records[i].date, bill->records[i].amount,
                   bill->records[i].category, bill->records[i].note);
        }
    }
}

// 预算管理
void budgetManagement() {
    double budget;
    printf("请输入每月支出预算限额：");
    scanf("%lf", &budget);

    // 获取当前月份
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int currentMonth = tm->tm_mon + 1;
    double currentExpense = 0;

    Bill bill;
    initBill(&bill);
    // 假设这里从文件或其他数据源加载账单数据到bill结构体中
    // 为了简化，这里没有实现数据加载功能

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
    printf("当前剩余可用预算：%.2f\n", remainingBudget);
}

// 月度统计
void monthlyStatistics() {
    // 获取当前月份
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int currentMonth = tm->tm_mon + 1;

    Bill bill;
    initBill(&bill);
    // 假设这里从文件或其他数据源加载账单数据到bill结构体中
    // 为了简化，这里没有实现数据加载功能

    double totalIncome = 0;
    double totalExpense = 0;
    double categoryAmount[20] = {0}; // 假设最多20个类别，可根据需要调整

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

    printf("本月总收入：%.2f\n", totalIncome);
    printf("本月总支出：%.2f\n", totalExpense);
    printf("各类别支出金额：\n");
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
        printf("\n个人账单管理系统\n");
        printf("1. 记录收入\n");
        printf("2. 记录支出\n");
        printf("3. 展示账单\n");
        printf("4. 按日期查询账单\n");
        printf("5. 按日期范围查询账单\n");
        printf("6. 按类别查询账单\n");
        printf("7. 预算管理\n");
        printf("8. 月度统计\n");
        printf("0. 退出\n");
        printf("请选择操作：");
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
                printf("请输入查询日期（格式：YYYY - MM - DD）：");
                scanf("%s", queryDate);
                queryBillsByDate(&bill, queryDate);
                break;
            }
            case 5: {
                char startDate[11];
                char endDate[11];
                printf("请输入开始日期（格式：YYYY - MM - DD）：");
                scanf("%s", startDate);
                printf("请输入结束日期（格式：YYYY - MM - DD）：");
                scanf("%s", endDate);
                queryBillsByDateRange(&bill, startDate, endDate);
                break;
            }
            case 6: {
                char queryCategory[20];
                printf("请输入查询类别：");
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
                printf("退出系统！\n");
                break;
            default:
                printf("无效选择，请重新选择！\n");
        }
    } while (choice!= 0);

    return 0;
}
