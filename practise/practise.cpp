// practise.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "src/weekcallback/weakcallback.h"
#include "src/variadic_template/variadic_template.h"
#include "src/copy_on_write/copy_on_write.h"

int main(int argc, char* argv[])
{
    CopyOnWrite::main(argc, argv);
    //WeakFactory::main(argc, argv);
    //VariadicTemplate::main(argc, argv);
	return 0;
}

