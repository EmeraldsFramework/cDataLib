#include "../../headers/_data_structures.h"

vectorT *string_split(stringT *str, stringT *delimeter) {
	/* Create a vector to store tokens */
	vectorT *str_tokens = new_vectorT();

	/* Create a duplicate */
	stringT *dup = string_dup(str);

	/* Add the first token */
	char *token = strtok(string_get(dup), string_get(delimeter));

	/* As long as the split token is not NULL continue inserting */
	while(token != NULL) {
		stringT *token_str = new_stringT(token);
		vector_add(str_tokens, token_str);
		token = strtok(NULL, string_get(delimeter));
	}

	/* Return the string tokens vector */
	return str_tokens;
}