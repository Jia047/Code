#include<stdio.h>
#include<string.h>

#define TRUE 1 // 函数执行成功
#define FALSE 0 // 函数执行失败

#define NAME_LENGTH 10 //名字的长度
#define CLASS_LENGTH 10 // 班级名称的长度
#define GRADE_LENGTH 10 // 年级名称的长度

typedef int status; // 函数返回结果

// 定义学生结构体
struct student {
    int id; // 学号
    char name[NAME_LENGTH]; // 学生名
    char class[CLASS_LENGTH]; // 班级
    char grade[GRADE_LENGTH]; // 年级
};

// 初始化学生数组，学号置 -1 表示该位置学生信息无效
status init(struct student * students, int length)
{
    for(int i = 0; i < length; i++)
    {
        students[i].id = -1;
        strcpy(students[i].name, "null");
        strcpy(students[i].class, "null");
        strcpy(students[i].grade, "null");
    }

    return TRUE;
}

// 将一个学生信息插入数组中，
// 其中 students是学生数组，length是数组总长度 - 1，index是插入位置，student为要插入的学生信息
status insert(struct student * students, int length, int index, struct student student)
{
    // 对index的合法性进行检查
    if(index < 0 || index > length)
    {
        printf("无效索引: %d\n", index);
        return FALSE;
    }

    students[index].id = student.id;
    strcpy(students[index].name, student.name);
    strcpy(students[index].class, student.class);
    strcpy(students[index].grade, student.grade);

    return TRUE;
}

// 检查两个名字是否相同，相同返回 TRUE，否则返回 FALSE
status check_name(char * name1, char * name2)
{
    if(strcmp(name1, name2) == 0)
    {
        return TRUE;
    }
    return FALSE;
}

// 根据学生的姓名查找学生信息，当有同名的学生时，返回第一个学生的位置,查找不到则返回 -1
int search_by_name(struct student * students, int length, char * name)
{
    for(int i = 0; i < length; i++)
    {
        // 学生信息有效
        if(students[i].id != -1)
        {
            if(check_name(students[i].name, name))
            {
                return i;
            }
        }
    }

    return -1;
}

// 打印数组中学生的名字，如果该位置没有学生名字，就用 null 表示
void show(struct student * students, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("(%d)%s ", i, students[i].name);
    }
    printf("\n");
}

// 输入学生信息并插入到指定位置
void input(struct student * students, int length)
{
    int id = 0;
    char name[NAME_LENGTH];
    char class[CLASS_LENGTH];
    char grade[GRADE_LENGTH];
    int index = 0;
    struct student stu;

    printf("请输入学生的学号：");
    scanf("%d", &id);
    printf("请输入学生的姓名：");
    scanf("%s", name);
    printf("请输入学生的班级：");
    scanf("%s", class);
    printf("请输入学生的年级：");
    scanf("%s", grade);

    printf("插入的位置(0 - %d):", length - 1);
    scanf("%d", &index);

    stu.id = id;
    strcpy(stu.name, name);
    strcpy(stu.class, class);
    strcpy(stu.grade, grade);

    printf("\n输入学生的信息为:[%d, %s, %s, %s]\n", stu.id, stu.name, stu.class, stu.grade);
    if(insert(students, length, index, stu))
    {
        printf("插入成功，目前学生列表为：");
        show(students, length);
    }
    else
    {
        printf("插入失败。\n");
    }
}

int main(int argc, char const *argv[]) {
    int length = 0;
    // 要查找的名字
    char name[NAME_LENGTH];

    printf("退出请按ctrl-c\n");
    printf("请先输入学生列表的长度：");
    scanf("%d", &length);

    struct student students[length];
    init(students, length);

    while(TRUE)
    {
        input(students, length);
        printf("要通过姓名获取学生信息的位置吗？不需要请输入 ‘no’:");
        scanf("%s", name);
        if(strcmp(name, "no") != 0)
        {
            printf("\n学生 %s 的位序是 %i\n", name, search_by_name(students, length, name));
        }
    }
    return 0;
}
