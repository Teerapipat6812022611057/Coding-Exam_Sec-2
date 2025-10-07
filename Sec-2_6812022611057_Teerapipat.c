#include <stdio.h>

float baseFee(char type) {
    if (type == 'O') return 15;      // ออนไลน์
    else if (type == 'B') return 40; // สาขา
    else if (type == 'A') return 20; // ATM
    else return 0;
}

int main() {
    int n, i;
    char type[20];
    float feeSum = 0, fee, totalValue, finalFee, rate = 0;
    int hasO = 0;

    printf("*** โปรแกรมคำนวณค่าธรรมเนียมธุรกรรม ***\n\n");
    printf("กรอกจำนวนครั้งของธุรกรรม (3-12): ");
    scanf("%d", &n);

    if (n < 3 || n > 12) {
        printf("จำนวนครั้งไม่ถูกต้อง ต้องระหว่าง 3 ถึง 12\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("กรอกประเภทช่องทางธุรกรรมที่ %d (O=ออนไลน์, B=สาขา, A=ATM): ", i + 1);
        scanf(" %c", &type[i]);
    }

    printf("กรอกมูลค่ารวมของธุรกรรมทั้งหมด (บาท): ");
    scanf("%f", &totalValue);

    for (i = 0; i < n; i++) {
        fee = baseFee(type[i]);

        if (type[i] == 'B') fee = fee * 1.2;  // สาขา บวก 20%
        if (type[i] == 'A') fee = fee * 0.9;  // ATM ลด 10%
        if (type[i] == 'O') hasO = 1;         // ออนไลน์มี 1 รายการขึ้นไป

        feeSum += fee;
    }

    finalFee = feeSum;

    if (totalValue > 50000 && hasO == 1) {
        finalFee = feeSum * 1.05;
        rate = 5.0;
    }

    printf("\n--- สรุปผลค่าธรรมเนียม ---\n");
    printf("จำนวนธุรกรรมทั้งหมด: %d ครั้ง\n", n);
    printf("ประเภทช่องทางที่ใช้: ");
    for (i = 0; i < n; i++) {
        printf("%c", type[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\n");
    printf("ค่าธรรมเนียมรวมพื้นฐาน: %.2f บาท\n", feeSum);
    printf("อัตราการปรับพิเศษ (สุทธิ): +%.2f%%\n", rate);
    printf("ค่าธรรมเนียมรวมสุดท้ายที่ต้องชำระ: %.2f บาท\n", finalFee);

    printf("\nขอบคุณที่ใช้โปรแกรมคำนวณค่าธรรมเนียมครับ\n");

    return 0;
}

