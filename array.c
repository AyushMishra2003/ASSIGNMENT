#include<stdio.h>
#include<conio.h>
struct array
{
    int capacity;
    int lastindex;
    int *ptr;
};
struct array * createarray(int cap)
{
    struct array *arr;
    arr=(struct array *)malloc(sizeof(struct array *));
    arr->capacity=cap;
    arr->lastindex=-1;
    arr->ptr=(int *)calloc(cap,4);
    return(arr);
}
void insert(struct array *arr,int index,int data)
{
    int i;
    if(index<0||index>arr->capacity)
        printf("invalid index");
    else
    {
        if(arr->lastindex==arr->capacity-1)
            printf("overflow condition");
        else
        {
            if(arr->lastindex==-1)
            {
                arr->ptr[0]=data;
                arr->lastindex+=1;
            }
            else
            {
            for(i=arr->lastindex;i>=index-1;i--)
            {
                arr->ptr[i+1]=arr->ptr[i];
              //  arr->lastindex+=1;
            }
            arr->ptr[index-1]=data;
            arr->lastindex+=1;
            }
        }
    }
}
void append(struct array *arr,int data)
{
    if(arr->lastindex==-1)
    {
        arr->ptr[0]=data;
        arr->lastindex+=1;
    }
    else
    {
          if(arr->lastindex==arr->capacity)
             printf("overflow condition");
        else
        {
            arr->ptr[arr->lastindex+1]=data;
            arr->lastindex+=1;
        }
    }
}
void view(struct array *arr)
{
    int i;
    for(i=0;i<=arr->lastindex;i++)
        printf("\n %d",arr->ptr[i]);
}
void delete(struct array *arr,int index)
{
    int i;
        if(index<0||index>arr->lastindex)
            printf("invalid index or empty array");
        else
        {
            for(i=index-1;i<=arr->lastindex-1;i++)
                arr->ptr[i]=arr->ptr[i+1];

            arr->lastindex-=1;

        }

}
void max(struct array *arr)
{
    int max,i;
    max=arr->ptr[0];
    for(i=1;i<=arr->lastindex;i++)
    {
        if(arr->ptr[i]>max)
            max=arr->ptr[i];
    }
    printf("maximum value is %d",max);
}
void min(struct array *arr)
{
    int min,i;
    min=arr->ptr[0];
    for(i=1;i<=arr->ptr[i];i++)
    {
        if(min>arr->ptr[i])
            min=arr->ptr[i];
    }
    printf("minimum value is %d",min);
}
void count(struct array *arr)
{
    int c=0,i;
    for(i=0;i<=arr->lastindex;i++)
        c++;
    printf("total count value is %d",c);
}
void search(struct array *arr,int data)
{
    int i,c=0;
    for(i=0;i<=arr->lastindex;i++)
    {
        if(arr->ptr[i]==data)
        {
            printf("\n %d element at %d index",data,i);
            break;
        }
        else
            printf("SORRY BUT ELEMENT IS NOT PRESENT");
    }
}
void edit(struct array *arr,int index,int data)
{
    if(index<0||index>arr->lastindex)
        printf("invalid index or overflow condition");
    else
    {
        arr->ptr[index]=data;
    }
}
void main()
{
    struct array *arr;
    arr=createarray(5);
    int choose,data,index;
    while(1)
    {
        printf("\n 1.INSERT");
        printf("\n 2.VIEW");
        printf("\n 3.Append");
        printf("\n 4.DELETE");
        printf("\n 5.MAX");
        printf("\n 6.MIN");
        printf("\n 7.COUNT");
        printf("\n 8.SEARCH");
        printf("\n 9.EDIT");
        printf("\n enter your choose");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1: printf("enter position and data you want to be insert");
                    scanf("%d %d",&index,&data);
                    insert(arr,index,data);
                    break;

           case 2: view(arr);
                    break;

           case 3: printf("enter data you want to be insert");
                   scanf("%d",&data);
                   append(arr,data);
                   break;

           case 4: printf("enter index you want to be delete");
                   scanf("%d",&index);
                   delete(arr,index);
                   break;
           case 5: max(arr);
                   break;

           case 6: min(arr);
                   break;

           case 7: count(arr);
                   break;


           case 8: printf("enter data you insert");
                   scanf("%d",&data);
                   search(arr,data);
                   break;

           case 9: printf("enter data and index you want to be insert");
                    scanf("%d %d",&index,&data);
                    edit(arr,index,data);
                    break;

           default: printf("invalid choose");

        }
    }
    getch();
}
