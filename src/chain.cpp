#include<cstdio>
#include"chain.h"
using namespace std;

struct node {
    int index;
    char str[size];
    node* before = NULL;
    node* after = NULL;
};

struct chain {
    int length;
    node* head = NULL;
    node* tail = NULL;
};

class OutOfRange {
    public:
        OutOfRange(chain* chain) {
            OutOfRange::chain = chain;
            OutOfRange::length = chain->length;
        }
        OutOfRange(chain* chain,int index) {
            OutOfRange::chain = chain;
            OutOfRange::length = chain->length;
            OutOfRange::index = index;
        }
    private:
        chain* chain;
        int length;
        int index;
};

// add a new node as the tail 
void add(chain* c,node* n) {
    if(c->length == 0) {
        n->index=0;
        c->head = n;
        c->tail = n;
    }
    else {
        c->tail->after = n;
        n->index = c->tail->index+1;
        c->tail = n;
    }
    c->length++;
}

//add a new node at the specified index
void add(chain* c,node* n,int index) {
    if(index > c->length+1) {throw OutOfRange(c,index);}

    for(node* i=c->head;i!=c->tail;i=i->after) {
        if(i->index == index-1) {
            n->after = i->after;
            n->before = i;
            i->after = n;
            n->index = index;

            if(c->tail->index == index-1) {c->tail = n;}
        }

        if(i->index >= index) {i->index++;}
    }
    c->length++;
}

//delete the tail
void del(chain* c) {
    if(c->length == 0) {throw OutOfRange(c);}
    node* n = c->tail;
    c->tail->before->after = NULL;
    c->tail = c->tail->before;
    delete n;
    c->length--;
}

//delete the specified node
void del(chain* c,int index) {
    for(node* i=c->head;i!=c->tail;i=i->after) {
        if(i->index == index) {
            if(c->tail->index == index) {
                del(c);
                continue;
            }

            i->before->after = i->after;
            i->after->before = i->before;
            delete i;
        }

        if(i->index >= index) {i->index--;}
    }
    c->length--;
}

//test code
int main() {
    return 0;
}