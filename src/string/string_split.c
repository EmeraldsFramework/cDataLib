#include "../../headers/_data_structures.h"

vectorT *string_split(stringT *str, stringT *delimeter) {
	vectorT *str_tokens = new_vectorT();
	stringT *dup = object_dup(str);

	/* Add the first token */
	char *token = strtok(string_get(dup), string_get(delimeter));
	while(token != NULL) {
		/* As long as the split token is not NULL continue inserting */
		stringT *token_str = new_stringT(token);
		vector_add(str_tokens, token_str);
		token = strtok(NULL, string_get(delimeter));
	}

	return str_tokens;
}