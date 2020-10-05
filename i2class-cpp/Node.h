#include "rport400.h"
class Node
{
public:
   Node();
   int _type;
   bool _isBracketed;
   virtual char *printNode(char *buf)=0;
   char *_numFunc;
   bool _isClass;
};
// A generic identifier class
class NodeId : public Node
{
public:
   char *_value;
   NodeId(int type, char *value);
   ~NodeId();
   char *printNode(char *buf);
};
// A generic operator class
class NodeOpr : public Node
{
public:
   NodeOpr(int type, Node *arg1, Node *arg2);
   ~NodeOpr();
   char *printNode(char *buf);
private:
   Node *_arg1, *_arg2;
};
// A generic procedure class
class NodeProcedure : public NodeId
{
public:
   NodeProcedure(char *value, NodeOpr *arg);
   ~NodeProcedure();
   char *printNode(char *buf);
protected:
   NodeOpr *_arg;
};
// A generic array class
class NodeArray : public NodeProcedure
{
public:
   NodeArray(char *value, NodeOpr *arg);
   char *printNode(char *buf);
};

NodeId *id(int type, char *value);
NodeOpr *opr(int type, Node *arg1, Node *arg2);
NodeProcedure *procedure(char *value, Node *arg);
NodeArray *array(char *value, Node *arg);
void walkResults(Node *node);

