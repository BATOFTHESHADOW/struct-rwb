#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char *ptr;
    uint64_t len;
} String;

typedef struct {
    uint8_t day;
    uint8_t month;
    uint16_t year;
} Date;

typedef struct {
    String Name;
    uint16_t Roll;
    Date Admission_Date;
    uint8_t Class;
    char Section;
    String Address;
    Date Date_Of_Birth;
} Student;

int main() {
    Student One;
    Student Two;
    FILE *fp;
    fp = fopen("output.bin", "wb");

    One.Name.ptr = "Shyamendra Hazra";
    One.Name.len = strlen(One.Name.ptr);
    One.Class = 1;
    One.Section = 'A';
    One.Roll = 1;
    One.Admission_Date.day = 13;
    One.Admission_Date.month = 5;
    One.Admission_Date.year = 2024;
    One.Address.ptr = "Parthapur mallikpara, Natagarh, Panihati, kol - 700113";
    One.Address.len = strlen(One.Address.ptr);
    One.Date_Of_Birth.day = 8;
    One.Date_Of_Birth.month = 11;
    One.Date_Of_Birth.year = 2002;

    fwrite(&One.Name.len, sizeof(uint64_t), 1,  fp);
    fwrite(One.Name.ptr, sizeof(char), One.Name.len,  fp);
    fwrite(&One.Class, sizeof(uint8_t), 1,  fp);
    fwrite(&One.Section, sizeof(char), 1,  fp);
    fwrite(&One.Roll, sizeof(uint16_t), 1,  fp);
    fwrite(&One.Admission_Date.day, sizeof(uint8_t), 1,  fp);
    fwrite(&One.Admission_Date.month, sizeof(uint8_t), 1,  fp);
    fwrite(&One.Admission_Date.year, sizeof(uint16_t), 1,  fp);
    fwrite(&One.Address.len, sizeof(uint64_t), 1, fp);
    fwrite(One.Address.ptr, sizeof(char), One.Address.len, fp);
    fwrite(&One.Date_Of_Birth.day, sizeof(uint8_t), 1,  fp);
    fwrite(&One.Date_Of_Birth.month, sizeof(uint8_t), 1,  fp);
    fwrite(&One.Date_Of_Birth.year, sizeof(uint16_t), 1,  fp);

    fclose(fp);


    fp = fopen("output.bin", "rb");
    
    fread(&Two.Name.len, sizeof(uint64_t), 1,  fp);
    Two.Name.ptr = (char*)malloc(Two.Name.len*sizeof(char));
    fread(Two.Name.ptr, sizeof(char), One.Name.len,  fp);
    fread(&Two.Class, sizeof(uint8_t), 1,  fp);
    fread(&Two.Section, sizeof(char), 1,  fp);
    fread(&Two.Roll, sizeof(uint16_t), 1,  fp);
    fread(&Two.Admission_Date.day, sizeof(uint8_t), 1,  fp);
    fread(&Two.Admission_Date.month, sizeof(uint8_t), 1,  fp);
    fread(&Two.Admission_Date.year, sizeof(uint16_t), 1,  fp);
    fread(&Two.Address.len, sizeof(uint64_t), 1, fp);
    Two.Address.ptr = (char*)malloc(Two.Name.len*sizeof(char));
    fread(Two.Address.ptr, sizeof(char), One.Address.len, fp);
    fread(&Two.Date_Of_Birth.day, sizeof(uint8_t), 1,  fp);
    fread(&Two.Date_Of_Birth.month, sizeof(uint8_t), 1,  fp);
    fread(&Two.Date_Of_Birth.year, sizeof(uint16_t), 1,  fp);
    
    fclose(fp);
    

    printf("%s\n", Two.Name.ptr);
    printf("%d\n", Two.Name.len);
    printf("%d\n", Two.Class);
    printf("%c\n", Two.Section);
    printf("%d\n", Two.Roll);
    printf("%d\n", Two.Admission_Date.day);
    printf("%d\n", Two.Admission_Date.month);
    printf("%d\n", Two.Admission_Date.year);
    printf("%s\n", Two.Address.ptr);
    printf("%d\n", Two.Address.len);
    printf("%d\n", Two.Date_Of_Birth.day);
    printf("%d\n", Two.Date_Of_Birth.month);
    printf("%d\n", Two.Date_Of_Birth.year);


    return 0;
}