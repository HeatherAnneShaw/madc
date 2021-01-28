////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////


#include <ast/ast.h>
#include <errors/errors.h>


std::map<Type, std::string> TypeMap = {
	{NONE,		"none"},
	{TRUTH,		"truth"},
	{INT,		"int"},
	{FLOAT,		"float"},
	{STRING,	"string"},
	{FUNCTION,	"function"},
	{LIST,		"list"}
};

std::string ast_type_to_string(Type type) {
	debug("ast_type_to_string");
	return TypeMap[type];
}

std::map<Operation, std::string> OpMap = {
	{LAND, "&&"},
	{LOR, 	"||"},
	{LEQ, 	"=="},
	{LNEQ, 	"!="},
	{LTEQ, 	"<="},
	{GTEQ, 	">="},
	{LT, 	"<"},
	{GT, 	">"},
	
	{BAND, 	"&"},
	{BOR, 	"|"},
	{BXOR, 	"^"},
	{BNOT, 	"!"},
	
	{ADD, 	"+"},
	{SUB, 	"-"},
	{MUL, 	"*"},
	{DIV, 	"/"},
	{MOD, 	"%"},
	{POW, 	"**"},
	
	{SUBSUB,	"--"},
	{ADDADD,	"++"},
	{ADDEQ,		"+="},
	{SUBEQ,		"-="},
	{POWEQ,		"**="},
	{MULEQ,		"*="},
	{DIVEQ,		"/="},
	{MODEQ,		"%="},
	{BANDEQ,	"&="},
	{BOREQ,		"|="},
	{BXOREQ,	"^="},
};

std::string ast_operation_to_string(Operation op) {
	debug("operation to string");
  return OpMap[op];
}

ValueNode* ValueNode::walk (void) {
	debug("value walk");
	return this;
}

ValueNode::ValueNode (void) {
	debug("value constructor");
	this->type = nodeType_value;
	this->vtype = NONE;
	if (current_scope != NULL)
		current_scope->value_table->push_back(this);
	else
		fatal_error("something isn't right with the current scope... email me what you did this should never happen");
}

ValueNode::~ValueNode (void) {}

ValueNode* ValueNode::oper (Operation op, ValueNode* right) {
	debug("default ValueNode::oper");
	if (right != NULL && right->type == nodeType_value)
		runtime_error("Operation " + ast_operation_to_string(op) + " not supported by type: " + this->type_str(), this);
	return NULL;
}

NoneNode::NoneNode (void) {
	debug("None constructor");
	this->vtype = NONE;
}

std::string NoneNode::to_string (void) {
	debug("None to_string");
	return "(none)";
}
std::string NoneNode::type_str (void) {
	debug("None type_str");
	return "none";
}


void free_value_walk (std::list<ValueNode*>* values) {
	debug("entering free value walk");
	while (! values->empty()) {
		delete values->front();
		values->pop_front();
	}
}


ValueNode* duplicate_value(ValueNode* node) {
	debug("entering duplicate value");
	switch (node->vtype) {
		case STRING:
			debug("STRING");
			return new StringNode(*((StringNode*) node)->value);
  	case INT:
			debug("INT");
			return new IntNode(((IntNode*) node)->value);
  	case FLOAT:
  		debug("FLOAT");
  		return new FloatNode(((FloatNode*) node)->value);
  	case NONE:
  		debug("NONE");
			return new NoneNode;
  	case TRUTH:
  		debug("TRUTH");
			return new TruthNode(((TruthNode*) node)->value);
  	case LIST:
			debug("LIST");
			return new ListNode(*((ListNode*) node)->value);
  	default:
  		fatal_error("invalid type on ast node duplication, email me");
  }
  return NULL;
}



