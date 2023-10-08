int main()
{
  FILE *arqum;
  FILE *arqdois;
  FILE *arqtres;
  char ch,ch1,leitor[100],leitor2[100];
  char nome1[20],nome2[20];

  printf("\nDigite o nome primeiro arquivo:\n");
  gets(nome1);

  arqum=fopen(nome1, "r"); //abre o arquivo para leitura
  if(NULL==arqum)
  {
      printf("O arquivo não pode ser aberto. \n" );
      system("Pause");
      exit (1);
  }
  ch=fgetc(arqum);
  while(ch!=EOF)
  {
      putchar(ch);
      ch=fgetc(arqum);
  }
  fclose (arqum);

  printf("\nDigite o nome do segundo arquivo:\n");
  gets(nome2);

  arqdois=fopen(nome2, "r"); //abre o arquivo para leitura
  if(NULL==arqum)
  {
      printf("O arquivo não pode ser aberto. \n" );
      system("Pause");
      exit (1);
  }
  ch1=fgetc(arqum);
  while(ch1!=EOF)
  {
      putchar(ch1);
      ch1=fgetc(arqdois);
  }
  fclose (arqdois);

  arqtres=fopen("arquivotres.txt","a+");
  if(NULL==arqtres)
  {
      printf("O arquivo não pode ser aberto. \n" );
      system("Pause");
      exit (1);
  }

  arqum=fopen(nome1, "r"); //abre o arquivo para leitura DE NOVO
  if(NULL==arqum)
  {
      printf("O arquivo não pode ser aberto. \n" );
      system("Pause");
      exit (1);
  }

  while(fgets(leitor,100,arqum)!=NULL);
  fputs(leitor,arqtres);
  fclose(arqtres);
  fclose (arqum); // fecha arquivo um

  arqdois=fopen(nome2, "r"); //abre o arquivo para leitura DE NOVO
  if(NULL==arqudois)
  {
      printf("O arquivo não pode ser aberto. \n" );
      system("Pause");
      exit (1);
  }

  arqtres=fopen("arquivotres.txt","a+");
  while(fgets(leitor2,100,arqdois)!=NULL);
  fputs(leitor2,arqtres);

  fclose (arqdois); // fecha arquivo dois
  fclose(arqtres);
return 0;
}
