#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Nhap so phan tu cho mang: ");
    scanf("%d", &n);

    int arr[100];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int choice;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In gia tri cac phan tu trong mang\n");
        printf("3. Tim gia tri nho nhat va lon nhat trong mang\n");
        printf("4. In tong cua tat ca cac phan tu\n");
        printf("5. Them mot phan tu vao cuoi mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan (Bubble sort)\n");
        printf("8. Tim kiem phan tu trong mang (Linear search)\n");
        printf("9. In ra tat ca cac so nguyen to trong mang\n");
        printf("10. Sap xep mang theo thu tu tang dan (Selection sort)\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Nhap so phan tu cho mang: ");
                scanf("%d", &n);
                printf("Nhap cac phan tu cua mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = ", i);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2: 
                printf("Gia tri cac phan tu trong mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;

            case 3: {
                int min = arr[0], max = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] < min) min = arr[i];
                    if (arr[i] > max) max = arr[i];
                }
                printf("Gia tri nho nhat: %d\n", min);
                printf("Gia tri lon nhat: %d\n", max);
                break;
            }

            case 4: { 
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += arr[i];
                }
                printf("Tong cua tat ca cac phan tu: %d\n", sum);
                break;
            }

            case 5: {
                int newValue;
                printf("Nhap gia tri can them: ");
                scanf("%d", &newValue);
                arr[n] = newValue;
                n++;
                printf("Da them phan tu vao mang.\n");
                break;
            }

            case 6: {
                int dir;
                printf("Nhap vi tri can xoa (0 - %d): ", n - 1);
                scanf("%d", &dir);
                if (dir >= 0 && dir < n) {
                    for (int i = dir; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Da xoa phan tu tai vi tri %d.\n", dir);
                } else {
                    printf("Vi tri khong hop le.\n");
                }
                break;
            }

            case 7: { 
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] < arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep giam dan:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            }

            case 8: {
                int target, found = 0;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &target);
                for (int i = 0; i < n; i++) {
                    if (arr[i] == target) {
                        printf("Gia tri %d xuat hien o vi tri %d.\n", target, i);
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    printf("Khong tim thay gia tri %d trong mang.\n", target);
                }
                break;
            }

            case 9: { 
                int primeFound = 0;
                printf("Cac so nguyen to trong mang:\n");
                for (int i = 0; i < n; i++) {
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                        primeFound = 1;
                    }
                }
                if (primeFound) {
                    printf("Khong co so nguyen to nao trong mang.\n");
                }
                printf("\n");
                break;
            }

            case 0:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
