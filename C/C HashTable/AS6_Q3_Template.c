#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 37
#define PRIME     13

enum Marker {EMPTY,USED};

typedef struct _slot{
    int key;
    enum Marker indicator;
    int next;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashFind(int key, HashSlot hashTable[]);

int hash(int key)
{
    return (key % TABLESIZE);
}

int main()
{
    int opt;
    int i;
    int key;
    int index;
    HashSlot hashTable[TABLESIZE];

    for(i=0;i<TABLESIZE;i++){
        hashTable[i].next = -1;
        hashTable[i].key = 0;
        hashTable[i].indicator = EMPTY;
    }

    printf("============= Hash Table ============\n");
    printf("|1. Insert a key to the hash table  |\n");
    printf("|2. Search a key in the hash table  |\n");
    printf("|3. Print the hash table            |\n");
    printf("|4. Quit                            |\n");
    printf("=====================================\n");

    printf("Enter selection: ");
    scanf("%d",&opt);
    while(opt>=1 && opt <=3){
        switch(opt){
            case 1:
                printf("Enter a key to be inserted:\n");
                scanf("%d",&key);
                index = HashInsert(key,hashTable);
                if(index <0)
                    printf("Duplicate key\n");
                else if(index < TABLESIZE)
                    printf("Insert %d at index %d\n",key, index);
                else
                    printf("Table is full.\n");
                break;
            case 2:
                printf("Enter a key for searching in the HashTable:\n");
                scanf("%d",&key);
                index = HashFind(key, hashTable);

                if(index!=-1)
                    printf("%d is found at index %d.\n",key,index);
                else
                    printf("%d is not found.\n",key);
                break;

            case 3:
                printf("index:\t key \t next\n");
                for(i=0;i<TABLESIZE;i++) printf("%d\t%d\t%d\n",i, hashTable[i].key,hashTable[i].next);
                break;
        }
        printf("Enter selection: ");
        scanf("%d",&opt);
    }
    return 0;
}

int HashInsert(int key, HashSlot hashTable[])
{
    // Write your code here

    int index = hash(key);

    // If the slot is empty add value to that slot
    if(hashTable[index].indicator == EMPTY){
        hashTable[index].key = key;
        hashTable[index].indicator = USED;
        return index;
    }


    while (1){
        // If there is no next value find empty slot using linear probing
        if(hashTable[index].next == -1){
            for (int i = index+1; i < TABLESIZE ; ++i) {
                // Add value if empty slot is found
                if(hashTable[i].indicator == EMPTY){
                    hashTable[i].key = key;
                    hashTable[i].indicator = USED;
                    hashTable[index].next = i;
                    return i;
                }
            }
             for(int j = 0;j < index+1; j++){
                  if(hashTable[j].indicator == EMPTY){
                     hashTable[j].key = key;
                     hashTable[j].indicator = USED;
                     hashTable[index].next = j;
                     return j;
                 }
             }
            return TABLESIZE+1;
        }
        else{
            index = hashTable[index].next;
        }

    }


}

int HashFind(int key, HashSlot hashTable[])
{
    for (int i = 0; i < 37; ++i) {
        if(hashTable[i].key == key){
            return i;
        }
    }
    return -1;
//    // Write your code here
//
//    int index = hash(key);
//
//    // If the key exists return index
//    if(hashTable[index].indicator == USED && hashTable[index].key == key){
//        return index;
//    }
//
//
//    while (hashTable[index].next != -1){
//        index = hashTable[index].next;
//
//        // If the key exists return index
//        if(hashTable[index].indicator == USED && hashTable[index].key == key){
//            return index;
//        }
//    }
//    return -1;
}