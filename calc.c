#include <calc.h>
#include <lexer.h>
#include <parser.h>
#include <interpreter.h>

int calc(const char* expr) {
dynamic_array_t token;
	lexer_tokenize(&token, expr);
	parser_node_t* node = parser_parse(&token);

	int result = eval(node);
    
    parser_delete(node);
	lexer_delete(&token);

    return result;
}