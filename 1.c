/*文件处理类题目
1. 编写程序，完成文件复制。
2. 编写程序，将合法C源程序每行前加上行号并删除其所有注释。
3. 编写程序，从文件中录入某班级学生成绩表，计算学生平均成绩并按从高到低排序，将排序后的学生信息写入到文件永久保存。*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;

    // 获取输入文件名和输出文件名
    printf("请输入输入文件名：");
    scanf("%s", inputFileName);
    printf("请输入输出文件名：");
    scanf("%s", outputFileName);

    // 打开输入文件
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("无法打开输入文件。\n");
        return 1;
    }

    // 打开输出文件
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("无法打开输出文件。\n");
        fclose(inputFile);
        return 1;
    }

    // 逐行读取输入文件并写入输出文件
    while (fgets(line, MAX_LINE_LENGTH, inputFile)) {
        lineNumber++;
        fprintf(outputFile, "%d: %s", lineNumber, line);
    }

    // 关闭文件
    fclose(inputFile);
    fclose(outputFile);

    printf("文件复制完成。\n");

    return 0;
}
//111