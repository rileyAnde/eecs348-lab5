#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS 12

//prototypes
void readSales(double sales[], const char *filename);
void generateMonthlyReport(double sales[]);
void summary(double sales[]);
void sixmonths(double sales[]);
void sort(double sales[]);

const char *monthNames[MONTHS] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int main() {
    double sales[MONTHS];
    const char *filename = "sales_data.txt";

    //read the sales data from the .txt file
    readSales(sales, filename);

    //make reports
    printf("Monthly Sales Report\n");
    printf("Month\t\tSales\n");
    generateMonthlyReport(sales);
    
    printf("\nSales Summary Report:\n");
    summary(sales);
    
    printf("\nSix-Month Moving Average Report:\n");
    sixmonths(sales);
    
    printf("\nSales Report (Highest to Lowest):\n");
    sort(sales);
    
    return 0;
}

//read from a .txt
void readSales(double sales[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    
    for (int i = 0; i < MONTHS; i++) {
        if (fscanf(file, "%lf", &sales[i]) != 1) {
            printf("Error: Invalid data in file\n");
            fclose(file);
            exit(1);
        }
    }
    fclose(file);
}

//generate the monthly sales report
void generateMonthlyReport(double sales[]) {
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s\t$%.2f\n", monthNames[i], sales[i]);
    }
}

//generate the sales summary report
void summary(double sales[]) {
    double min = sales[0], max = sales[0], sum = 0.0;
    int minMonth = 0, maxMonth = 0;
    
    for (int i = 0; i < MONTHS; i++) {
        sum += sales[i];
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
    }
    double average = sum / MONTHS;
    
    printf("Minimum sales: $%.2f (%s)\n", min, monthNames[minMonth]);
    printf("Maximum sales: $%.2f (%s)\n", max, monthNames[maxMonth]);
    printf("Average sales: $%.2f\n", average);
}

//six month averages
void sixmonths(double sales[]) {
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        double average = sum / 6.0;
        printf("%s-%s\t$%.2f\n", monthNames[i], monthNames[i + 5], average);
    }
}

//sort sales for report
void sort(double sales[]) {
    int indices[MONTHS];
    
    //make indices for months
    for (int i = 0; i < MONTHS; i++) {
        indices[i] = i;
    }
    
    //bubble sort
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - i - 1; j++) {
            //compare and swap when needed
            if (sales[indices[j]] < sales[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    //print
    printf("Month\t\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s\t$%.2f\n", monthNames[indices[i]], sales[indices[i]]);
    }
}
