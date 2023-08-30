

// // 二分查找
// Position BinarySearch( List L, ElementType X )
// {    
//     int left=1,right=L->Last;
//     int middle=(left+right)/2;
//     while(left<=right)
//     {    
//         middle=right-(right-left)/2;
//         if(L->Data[middle]==X) 
//             return middle;
//         if(L->Data[middle]>X) 
//         {    
//             right=middle-1;
//         }    
//         if(L->Data[middle]<X)
//         {    
//             left=middle+1;
//         }  
//     }
//     return NotFound;
// }

// 二分查找递归
// int find(int* a,int x,int begin,int end)
// {
//   int mid = (begin+end)/2;
//   if(begin>end) return error;
//   if(a[mid]==x) return mid;
//   if(a[mid]<x) begin = mid+1;
//   if(a[mid]>x) end = mid-1;
//   return find(a,x,begin,end);
// }

// 归并排序
// void mergesort(int A[], int temp[],int left, int right) {
//     //终止条件
// 	if (left == right) return;    
//     //分解与解决过程
// 	int mid = (left + right) / 2;
// 	mergesort(A, temp, left, mid);
// 	mergesort(A, temp, mid + 1, right);
// 	for (int i = left; i <= right; i++) // Copy
// 		temp[i] = A[i];
//     //合并过程
// 	int i1 = left; int i2 = mid + 1;
// 	for (int curr = left; curr <= right; curr++) {
// 		if (i1 > mid)      // Left exhausted
// 			A[curr] = temp[i2++];
// 		else if (i2 > right)  // Right exhausted
// 			A[curr] = temp[i1++];
// 		else if (temp[i1] < temp[i2])
// 			A[curr] = temp[i1++];
// 		else A[curr] = temp[i2++];
// 	}
// }

//     /*插入排序*/
//     void InsertSort(lint* num,lint N)
//     {
//       for(int p=1;p<N;p++)
//       {
//         int i=p;
//         lint temp=num[p];
//         for(;i>0&&num[i-1]>temp;i--)
//         num[i]=num[i-1];
//         num[i]=temp;
//       }
//     }

//     /* 希尔排序*/
//     void ShellSort(lint* num,int N)
//     {
//       for(int S=N/2;S>0;S/=2)
//       {
//         for(int p=S;p<N;p++)
//         {
//           int i=p;
//           lint temp=num[p];
//           for(;i>=S&&num[i-S]>temp;i-=S)
//           num[i]=num[i-S];
//           num[i]=temp;
//         }
//       }
//     }

//     /*选择排序*/
//     void SelectSort(lint* num,int N)
//     {
//       for(int i=0;i<N;i++)
//       {
//         int Min=Select(i,num,N);
//         Swap(num,i,Min);
//       }
//     }
//     int Select(int n,lint* num,int N)
//     {
//       int min=n;
//       for(int i=n;i<N;i++)
//       {
//         if(num[i]<num[min]) min=i;
//       }
//       return min;
//     }
//     void Swap(lint* num,int i,int Min)  
//     {                                
//       if(num[i]==num[Min]) return;         //不适用于两个相同的数
//       num[i]^=num[Min]^=num[i]^=num[Min];
//     }

//     /*堆排序*/
//     void HeapSort(lint* num,int N)
//     {
//       H Heap=InitHeap(num,N);
//       for(int i=0;i<N;i++)
//       {
//         int Min=DeleteH(i,Heap,N);
//       }
//       free(Heap);
//     }
//     int DeleteH(int n,H Heap,lint N)
//     {
//       Swap(Heap->data,0,Heap->size-1);
//       Heap->size--;
//       Percdown(0,Heap);
//       return Heap->size;   //总是忘了return?
//     }
//     H InitHeap(lint* num,int N)
//     {
//       H Heap=(H)malloc(sizeof(struct heap));
//       Heap->size=N;
//       Heap->data=num;
//       for(int i=N/2;i>=0;i--)
//       {
//         Percdown(i,Heap); //O(N)建立最大堆
//       }
//       return Heap;
//     }
//     void Percdown(int n,H Heap)
//     {
//       lint temp=Heap->data[n];
//       int N=Heap->size;   //一定要存一个Temp临时变量，不能存下标啊，下标的值已经变了啊
//       int parent=n,child;
//       for(;parent*2+1<N;parent=child)
//       {
//         child=parent*2+1;
//         if(child!=N-1&&Heap->data[child]<Heap->data[child+1]) child++;
//         if(temp>Heap->data[child])break;  //这也是
//         else Heap->data[parent]=Heap->data[child];
//       }
//       Heap->data[parent]=temp;  //这里就不能写Heap->data[n] !!
//     }

//     /*归并排序*/

//     /*递归算法*/
//     void Merge(lint* num,lint* temp,int lef,int rig,int rigend)
//     {
//       int count=lef,mid=rig-1;
//       int len=rigend-lef+1;
//       while(lef<=mid&&rig<=rigend)  
//       {
//         if(num[lef]<=num[rig])temp[count++]=num[lef++]; //等于时左边优先保持稳定
//         else temp[count++]=num[rig++];
//       }
//       while(lef<=mid)temp[count++]=num[lef++];
//       while(rig<=rigend)temp[count++]=num[rig++];
//       for(int i=0;i<len;i++,rigend--)
//       num[rigend]=temp[rigend];  //不能同时减减！！！！
//     }
//     void MergeSort(lint* num,int N)
//     {
//       lint* temp=(lint*)malloc(sizeof(lint)*N);
//       Mergesort(num,temp,0,N-1);
//       free(temp);
//     }
//     void Mergesort(lint* num,lint* temp,int lef,int rig)
//     {
//       int mid=(lef+rig)/2;
//       if(lef<rig)
//       {
//         Mergesort(num,temp,lef,mid);
//         Mergesort(num,temp,mid+1,rig);
//         Merge(num,temp,lef,mid+1,rig);
//       }
//       else return;
//     }

//     /*非递归*/
//     void Mergesort1(lint* num,lint* temp,int len,int N)
//     {
//       int lef=0;
//         for(;lef<=N-2*len;lef+=2*len)  //这里要加等于，可能刚好剩下两个序列
//         {
//           int rig=lef+len;
//           int rigend=lef+2*len-1;
//           Merge(num,temp,lef,rig,rigend);
//         }
//         if(lef+len<N) Merge(num,temp,lef,lef+len,N-1);//超过一个序列
//         else for(int i=lef;i<N;i++)temp[i]=num[i];  //只有一个序列  //这里是往temp  
//     }
//     void MergeSort1(lint* num,int N)
//     {
//       lint* temp=(lint*)malloc(sizeof(lint)*N);
//       int len=1;
//       while(len<N)
//       {
//         Mergesort1(num,temp,len,N);
//         len*=2;
//         Mergesort1(temp,num,len,N);
//         len*=2;
//       }
//       free(temp);
//     }
  
//   /*快排函数*/
//     void QuickSort(lint* num,int N)
//     {
//       qSort(num,0,N-1);
//     }
//     void qSort(lint* num,int left,int right)
//     {
//       int cutoff=100;
//       if(right-left<cutoff)InsertSort(num+left,right);             //或者小于等于cutoff调用简单排序
//       else
//       {
//         int a=left,c=right-1;
//         int mid=Middle(num,left,(left+right)/2,right);
//         for(;;)
//         {
//           while(num[++a]<num[mid]);
//           while(num[--c]>num[mid]);
//           if(a<c) swap(num[a],num[c]);
//           else break;
//         }
//         Swap(num[a],num[mid]);
//         qSort(num,left,a-1);   //以mid元素存放的位置为分界线
//         qSort(num,a+1,right); 
//       } 
//     }
//     int Middle(lint* num,int a,int b,int c)
//     {
//       if(num[a]>num[b]) Swap(num[a],num[b]);
//       if(num[a]>num[c]) Swap(num[a],num[c]);
//       if(num[b]>num[c]) Swap(num[b],num[c]);
//       Swap(num[b],num[c-1]);
//       return c-1; //也可以直接返回值，而非下标
//     }
//     void Swap(lint& a,lint& b)
//     {
//       if(a==b)return;
//       a^=b^=a^=b;
//     }

//     /*函数库*/
//     int compare(const void* a,const void* b)
//     {
//       return (int)((*(lint*)a)-(*(lint*)b));  //返回值必须是int ,long int 也不行
//     }                                         //最后要强制类型转换


// 计数排序//
// void CountSort(lint* num,int N)
// {
//   lint min=num[0],max=num[0];
//   for(int i=0;i<N;i++)
//   {
//     if(num[i]>max)max=num[i];
//     if(num[i]<min)min=num[i];
//   }
//   lint count[max-min+1]={0}; //找到计数数组
//   for(int i=0;i<N;i++)
//   {
//     count[num[i]]++;
//   }
//   int flag=0;
//   for(int i=0;i<max-min+1;i++)
//   {
//     if(count[i]!=0)
//     {
//       if(flag)cout<<endl;
//       cout<<i<<":"<<count[i];
//       flag=1;
//     }
//   }
// }

// /*表排序*//*物理排序*/
// lint table[Maxsize];
// void TableSort(lint* num,int N)
// {
//   for(int i=0;i<N;i++)table[i]=i;
//   qsort(table,N,sizeof(lint),compare);
// }
// int compare(const void* a,const void* b)
// {
//   return (int)(num[*(int*)a]-num[*(int*)b]);
// }
// void PhysicalSort(lint*num,int N)
// {
//   int begin=num[0];
//   for(int i=0;i<N;)
//   {
//     int temp=table[i];
//     if(temp!=i)   //访问的数未被正确设置
//     {
//       if(table[temp]==temp)   //要访问的下一个已经是环末位
//       {
//         num[i]=begin;
//         table[i]=i;  //关键 不要遗忘
//         for(int j=0;j<N;j++) //查找下一个环的开始
//         {
//           if(table[j]==j)continue; //已正确设置
//           else 
//           {
//             begin=num[j];  //调整begin
//             i=j;
//             break;
//           }
//         }
//       }
//       else     //还在环内
//       {
//         num[i]=num[temp];
//         table[i]=i;
//         i=temp;
//       }
//     }
//     else          //一开始就已设置完毕也要考虑进去!!!!!!!!!!!!!!!!!
//     {
//       i++;           //不能随意++,不能写括号里
//       begin=num[i];  //关键
//     }
//   }
//   int flag=0;
//   for(int i=0;i<N;i++)
//   {
//     if(flag)cout<<" ";
//     cout<<num[i];
//     flag=1;
//   }
// }