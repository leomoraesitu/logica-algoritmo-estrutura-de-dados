#include <stdio.h>

int main()
{
	float peso, altura, imc;

	printf("Digite o peso: ");
	scanf("%f", &peso);

	printf("Digite a altura: ");
	scanf("%f", &altura);

	imc = (peso / (altura * altura));

	printf("\n%.1f kg / %.2f m x %.2f m = IMC %.1f", peso, altura, altura, imc);

	if (imc <= 18.5)
	{
		printf("\n\nAbaixo do peso");
		printf("\n(Ate 18,5 Kg)");
	}
	else
	{
		if (imc >= 18.5 && imc < 25.0)
		{
			printf("\n\nSaudavel");
			printf("\n(De 18,5 a menor que 25,0 Kg)");
		}
		else
		{
			if (imc >= 25.0 && imc < 30.0)
			{
				printf("\n\nSobrepeso");
				printf("\n(De 25,0 a menor que 30,0 Kg)");
			}
			else
			{
				if (imc >= 30.0 && imc < 35.0)
				{
					printf("\n\nObesidade Grau I");
					printf("\n(De 30,0 a menor que 35,0 Kg)");
				}
				else
				{
					if (imc >= 35.0 && imc < 40.0)
					{
						printf("\n\nObesidade Grau II (severa)");
						printf("\n(De 35,0 a menor que 40,0 Kg)");
					}
					else
					{
						if (imc >= 40.0)
						{
							printf("\n\nObesidade Grau III (morbida)");
							printf("\n(De 40,0 Kg em diante)");
						}
					}
				}
			}
		}
	}
	
	return 0;
}
