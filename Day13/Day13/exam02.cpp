#include "stdafx.h"
#include "../../duktape/src/duktape.h"

static duk_ret_t test_print(duk_context *ctx) {
	printf("hello duktape\n");

	return 0;
}

int main() {
	duk_context *pMainCtx = duk_create_heap_default();

	duk_eval_string(pMainCtx, "1+2");
	int nResult = duk_get_int(pMainCtx, -1);

	printf("1 + 2 = %d\n", nResult);

	duk_push_c_function(pMainCtx, test_print, 0);
	duk_put_global_string(pMainCtx, "print");
	duk_eval_string_noresult(pMainCtx, "print();");

	duk_destroy_heap(pMainCtx);

	return 0;
}