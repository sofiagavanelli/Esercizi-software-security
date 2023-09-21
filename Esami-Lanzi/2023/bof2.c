#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

struct auth
{
	char call[16];
	int admin;
	char execute[512];
};

struct auth a;

void admin(struct auth *a)
{
	if (a->admin == 0xdeadb0f)
	{
                printf("SIAMO ENTRATI");
		mprotect((unsigned)a & ~0xfff, sizeof(*a), PROT_READ | PROT_WRITE | PROT_EXEC);
		(*(void(*)())a->execute)();
	}
}

int main(int argc, char **argv)
{

	if (argc == 2)
	{
		a.admin = 0;
                printf("a.exe %x\n", a.execute);
                printf("a.admin add %x\n", &a.admin);
		strcpy(a.call, argv[1]);
                printf("a.exe %x\n", a.execute);
		admin(&a);
	}

	return 0;
}
