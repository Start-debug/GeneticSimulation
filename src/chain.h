const int size = 3;

struct node;
struct chain;

class OutOfRange;

void add(chain* chain,node* node);
void add(chain* chain,node* node,int index);
void del(chain* chain);
void del(chain* chain,int index);