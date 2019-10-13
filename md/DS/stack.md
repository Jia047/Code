- 结构体
```C
typedef struct {
    int top;        // 栈顶指针
    void *elem;     // 栈内元素，设置为 void*，这样可以存储任意类型
} Stack;
```

- 关键函数
> 使用宏来定义内存分配和转型函数，以便实现存储指定类型
```C
#define ALLOC(elem,size,type) ((elem) = (type*)malloc((size) * sizeof(type)))

#define TRANSFORM(e,type) (type)e
```
- 操作函数
    - 初始化：iniit(S, size, type)
    - 取栈顶: top(S);
    - 出栈: pop(S);
    - 入栈: push(S, e);
    - 销毁: des(S);
