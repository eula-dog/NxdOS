#include <stdio.h>

int main() {
    FILE *file;
    char buffer[100];

    // 打开文件
    file = fopen("D:\\NxdOS\\NxdOS\\utils\\boot.bin", "r");
    if (file == NULL) {
        printf("无法打开文件\n");
        return 1;
    }

    // 读取文件内容
    while (fgets(buffer, 100, file) != NULL) {
        printf("%s", buffer);
    }

    // 关闭文件
    fclose(file);

    return 0;
}
