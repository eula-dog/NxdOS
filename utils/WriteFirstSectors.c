#include <stdio.h>
#include <stdlib.h>   //lib头文件用于调用system函数



void printBinary(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        if ((byte >> i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf(" ");
}

//"D:\\NxdOS\\NxdOS\\utils\\boot.bin"
//D:\\NxdOS\\NxdOS\\utils\\result\\result.img
int main() {

    char write_path[] = "D:\\NxdOS\\NxdOS\\utils\\result\\result.img";

    FILE *input_file, *output_file;
    unsigned char buffer[1024];
    size_t bytes_read;

    // 打开输入二进制文件
    input_file = fopen("D:\\NxdOS\\NxdOS\\utils\\boot.bin", "rb");
    if (input_file == NULL) {
        printf("无法打开输入文件\n");
        return 1;
    }

    // 创建或打开输出二进制文件
    output_file = fopen(write_path, "wb");
    if (output_file == NULL) {
        printf("无法打开输出文件\n");
        fclose(input_file);
        return 1;
    }

    // 从输入文件读取数据并写入输出文件
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        fwrite(buffer, 1, bytes_read, output_file);
    }

    // 关闭文件
    fclose(input_file);
    fclose(output_file);

    system("pause");

    return 0;
}
