#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

typedef unsigned char u8;
typedef unsigned int u32;

void initRingbuffer(void);
int writeRingbuffer(u8*buffer,u32 len);
int readRingbuffer(u8*buffer,u32 len);

u32 getRingbufferValidLen(void);
void releaseRingbuffer(void);


#endif

#define BUFER_SIZE  16   //

u32 vaildLen =0;
static u8* pHead = NULL;		//used storge address
static u8* pTail = NULL;		//

static u8* pValid = NULL;		//used buff address
static u8* pValidTail = NULL  ;  //used...
void initRingbuffer(){
	if(pHead ==NULL){
		pHead = (u8*)malloc(BUFER_SIZE);

	}
	pValid = pValidTail =pHead;
	pTail = pHead+BUFER_SIZE;
	vaildLen =0;
	
}
int main(int argc, char const *argv[])
{
	char c;
	u32 readLen;
	u8 readBuffer[10];

	return 0;
}


/*************************************************************/ 


void float_task(void* pvPatameters){
	static float  float_num=0.00f;
	while (1)
	{
		float_num+=0.01f;
		printf("float :  %.4f \r\n",float_num);
		vTaskDelay(1000);
	}

}




/*************************************************************/ 
#include <stdio.h>
/*************************************************************/ 
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{
while ((USART1->SR & 0X40) == 0);
USART1->DR = (uint8_t) ch;
return ch;
}
/*************************************************************/ 
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{

    while ((UART4->ISR & 0X40) == 0);
    UART4->TDR = (uint8_t) ch;
    return ch;
}
/*************************************************************/ 

#define err_t(A) do{printf(A);putchar(10);return 0 ;}while(0)

#define SET_BIT_N(x,n)   (x|(1U<<(n-1)))

#define CLEAN_BIT_N(x,n) (x&~(1U<<(n-1)))

#define CLEAN_BIT_N_M(x,n,m) (x|((~0U)>>(32-(m-n+1))<<(n-1)))
/*************************************************************/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(int argc, char const *argv[])
{
    cJSON *json = cJSON_CreateObject();
    cJSON_AddItemToObject(json,"name",cJSON_CreateString("001"));

    cJSON_AddNumberToObject(json,"age",26);

    cJSON *array = NULL;
    cJSON_AddItemToObject(json,"love",array = cJSON_CreateArray());
    cJSON_AddItemToArray(array,cJSON_CreateString("LOL"));
    cJSON_AddItemToArray(array,cJSON_CreateString("LOL"));
    cJSON_AddItemToArray(array,cJSON_CreateString("LOL"));
    cJSON_AddNumberToObject(json,"score",59);
    cJSON_AddNumberToObject(json,"score",100);
    char *buf =cJSON_Print(json);
    FILE *pf = fopen("1.json","w");
    fwrite(buf,strlen(buf),1,pf);
    free(buf);
    fclose(pf);
    cJSON_Delete(json);

    return 0;
}
/*************************************************************/ 



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define container_of(ptr, type, member) \
	(type *)((char *)ptr - (unsigned int)&((type *)0)->member)

struct node_t {
	struct node_t *pre;
	struct node_t *next;
};

struct person {
	char *name;
	int age;
	struct node_t node;
};

struct list {
	char *name; /* A班 */
	struct node_t head;
};

void InitList(struct list *pList, char *name) {
	pList->name = name;
	pList->head.next = &pList->head;
	pList->head.pre = &pList->head;
}

void AddItemToList(struct list *pList, struct node_t *new_node) {
	struct node_t *last = pList->head.pre;

	new_node->next = &pList->head;
	last->next = new_node;
	new_node->pre = last;
	pList->head.pre = new_node;
}

void AddItemAfter(struct node_t *pre, struct node_t *new_node) {
	struct node_t *right = pre->next;

	pre->next = new_node;
	new_node->next = right;

	right->pre = new_node;
	new_node->pre = pre;
}

void DelItemFromList(struct list *pList, struct node_t *node) {
	struct node_t *left = node->pre;
	struct node_t *right = node->next;

	left->next = right;
	right->pre = left;
}

int CmpPersonAge(struct node_t *pre, struct node_t *next) {
	struct person *p;
	struct person *n;

	p = container_of(pre, struct person, node);
	n = container_of(next, struct person, node);

	if (p->age < n->age)
		return -1;
	else
		return 0;
}

void SortList(struct list *pList) {
	struct node_t *pre1 = &pList->head;
	struct node_t *pre2;
	struct node_t *cur = pre1->next;
	struct node_t *next;
	struct node_t *tmp;

	while (cur != &pList->head) {
		pre2 = cur;
		next = cur->next;
		while (next != &pList->head) {
			if (CmpPersonAge(cur, next) == 0) {
				/* 交换节点 */
				/* 1. del cur */
				DelItemFromList(pList, cur);

				/* 2. del next */
				DelItemFromList(pList, next);

				/* 3. 在pre1之后插入next */
				AddItemAfter(pre1, next);

				/* 4. 在pre2之后插入cur */
				if (pre2 == cur)
					AddItemAfter(next, cur);
				else
					AddItemAfter(pre2, cur);

				/* 5. cur/next指针互换 */
				tmp = cur;
				cur = next;
				next = tmp;
			}

			pre2 = next;
			next = next->next;
		}

		pre1 = cur;
		cur = cur->next;
	}

}

void PrintList(struct list *pList) {
	int i = 0;

	struct node_t *node = pList->head.next;
	struct person *p;

	while (node != &pList->head) {
		p = container_of(node, struct person, node);
		printf("person %d: %s is %d\r\n", i++, p->name, p->age);

		/* 后面还有人, 移动到下一个 */
		node = node->next;
	}
}

int main(int argc, char **arg) {
	struct list a_list;
	int i;

	struct person p[] = { { "p1", 10, { NULL } }, { "p2", 20, { NULL } }, {
			"p3", 13, { NULL } }, { "p4", 41, { NULL } },
			{ "p5", 56, { NULL } }, { "p6", 12, { NULL } },
			{ "p7", 9, { NULL } }, { "p8", 21, { NULL } },
			{ "p9", 22, { NULL } }, { "p10", 21, { NULL } }, { "p11", 20,
					{ NULL } }, { NULL, 0, { NULL } }, };

	HAL_Init();

	MX_USART1_UART_Init();

	InitList(&a_list, "A_class");

	i = 0;
	while (p[i].name != NULL) {
		AddItemToList(&a_list, &p[i].node);
		i++;
	}

	printf("add all person:\r\n");
	PrintList(&a_list);

	DelItemFromList(&a_list, &p[3].node);

	printf("del person %s:\r\n", p[3].name);
	PrintList(&a_list);

	DelItemFromList(&a_list, &p[0].node);

	printf("del person %s:\r\n", p[0].name);
	PrintList(&a_list);

	SortList(&a_list);
	printf("sort list, all person:\r\n");
	PrintList(&a_list);

	while (1) {
	}
}

void Error_Handler(void) {
	printf("Error\r\n");
	while (1) {
	}
}



/* nerdvm.racknerd  9c614d16f4 */
