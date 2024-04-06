#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

int calculaIdade(int anoNasc, int mesNasc, int diaNasc){

    struct tm {
        int tm_sec;
        int tm_mday;
        int tm_mon;
        int tm_year;
    };

    time_t segundos;

    time(&segundos);
    struct tm dataAtual;

    dataAtual.tm_sec = localtime(&segundos)->tm_sec;
    dataAtual.tm_mday = localtime(&segundos)->tm_mday;
    dataAtual.tm_mon = localtime(&segundos)->tm_mon;
    dataAtual.tm_year = localtime(&segundos)->tm_year;


    int anoAtual = dataAtual.tm_year+1900;
    int mesAtual = dataAtual.tm_mon+1;
    int diaAtual = dataAtual.tm_mday;
    int Idade;

    printf("\nA data atual é %d/%d/%d", diaAtual, mesAtual, anoAtual);

    Idade = anoAtual - anoNasc;

  if(mesNasc<mesAtual){
        printf("\nO paciente tem %d anos.\n", Idade);
  }else if(mesNasc == mesAtual){
      if(diaAtual>diaNasc){
            printf("\nO paciente tem %d anos\n", Idade);
      }else{
        Idade = Idade -1;
            printf("\nO paciente tem %d anos\n", Idade);
      }
  }else{
      Idade = Idade -1;
      printf("\nO paciente tem %d anos\n", Idade);
  }


  return Idade;
}



void PACIENTES_COVID(void){
        //REGISTRO DE PACIENTES - VER DEPOIS - COMO LER ARQUIVO - COMO PUXAR DADOS DO ARQUIVO E UTILIZAR ELE
    FILE *registroPacientes;

        typedef struct{
            char rua[50];
            char numero[10];
            char bairro[50];
            char cidade[50];
            char estado[50];
            char CEP[15];
        } Endereco;

        typedef struct{
            int dia;
            int mes;
            int ano;
        } DataNascimento;

        typedef struct{
            int dia;
            int mes;
            int ano;
        } DataDiagnostico;

        typedef struct{
            char nome[50];
            char CPF[11];
            char telefone[12];
            Endereco enderecoPaciente;
            DataNascimento dataNascismento;
            DataDiagnostico dataDiagnostico;
        } Registro;

        Registro Pacientes;

        registroPacientes = fopen("dadosPacientes.txt", "a");

            if(registroPacientes == NULL){
            printf("Erro na abertura do arquivo!");
            }

            printf("\nPor favor não utilize acento nos dados do paciente!!");

            printf("\nDigite o nome do paciente:");
                setbuf(stdin,NULL);
                fgets(Pacientes.nome,50,stdin);

            printf("\nDigite o CPF do paciente:");
                setbuf(stdin,NULL);
                scanf("%s", Pacientes.CPF);

            printf("\nDigite o telefone do paciente:");
                setbuf(stdin,NULL);
                scanf("%s", Pacientes.telefone);

            printf("\nAgora digite os dados do endereço do paciente:");

            setbuf(stdin,NULL);
            printf("\nRua:");
                setbuf(stdin,NULL);
                fgets(Pacientes.enderecoPaciente.rua,50,stdin);

            printf("\nNumero:");
                setbuf(stdin,NULL);
                scanf("%s", Pacientes.enderecoPaciente.numero);

            printf("\nBairro:");
                setbuf(stdin,NULL);
                fgets(Pacientes.enderecoPaciente.bairro,50,stdin);

            printf("\nCidade:");
                setbuf(stdin,NULL);
                fgets(Pacientes.enderecoPaciente.cidade,50,stdin);

            printf("\nEstado:");
                setbuf(stdin,NULL);
                fgets(Pacientes.enderecoPaciente.estado,50,stdin);

            printf("\nCEP:");
                setbuf(stdin,NULL);
                scanf("%s", Pacientes.enderecoPaciente.CEP);

            printf("\nAgora digite a data de nascimento do paciente\n");
            printf("\nDia:");
                setbuf(stdin,NULL);
                scanf("%d", &Pacientes.dataNascismento.dia);
            printf("\nMês:");
                setbuf(stdin,NULL);
                scanf("%d", &Pacientes.dataNascismento.mes);
            printf("\nAno:");
                setbuf(stdin,NULL);
                scanf("%d", &Pacientes.dataNascismento.ano);

            printf("\nAgora digite a data de diagnóstico do paciente\n");
            printf("\nDia:");
                setbuf(stdin,NULL);
                scanf("%d", &Pacientes.dataDiagnostico.dia);
            printf("\nMês:");
                setbuf(stdin,NULL);
                scanf("%d", &Pacientes.dataDiagnostico.mes);
            printf("\nAno:");
                setbuf(stdin,NULL);
                scanf("%d", &Pacientes.dataDiagnostico.ano);

            fprintf(registroPacientes, "\n ****Dados do Paciente****\n\nNome: %s \nCPF: %s \nTelefone:%s \nEndereço: \nRua:%s \nNumero: %s \nBairro: %s \nCidade: %s \nEstado: %s \nCEP: %s  \nData de Nascimento %d / %d / %d \n Data do diagnóstico: %d / %d / %d \n", Pacientes.nome, Pacientes.CPF, Pacientes.telefone, Pacientes.enderecoPaciente.rua, Pacientes.enderecoPaciente.numero, Pacientes.enderecoPaciente.bairro, Pacientes.enderecoPaciente.cidade, Pacientes.enderecoPaciente.estado, Pacientes.enderecoPaciente.CEP, Pacientes.dataNascismento.dia, Pacientes.dataNascismento.mes, Pacientes.dataNascismento.ano, Pacientes.dataDiagnostico.dia, Pacientes.dataDiagnostico.mes, Pacientes.dataDiagnostico.ano);

        fclose(registroPacientes);

        //Verificar se o paciente possui alguma comorbidade e se tem mais de 65 anos

        int Comorbidade;

        printf("\nO paciente possui alguma das comorbidades listadas abaixo?");

        printf("\n ****LISTA DE COMORBIDADES****");

            printf("\n-Diabetes");
            printf("\n-Doença Pulmonar Obstrutiva Crônica");
            printf("\n-Hipertensão");
            printf("\n-Asma");
            printf("\n-Fibrose pulmonar");
            printf("\n-Cardiopatias");
            printf("\n-Insuficiência cardíaca (IC)");
            printf("\n-Miocardiopatias e Pericardiopatias");
            printf("\n-Doenças da Aorta, dos Grandes Vasos e Fístulas arteriovenosas");
            printf("\n-Arritmias cardíaca");
            printf("\n-Próteses valvares e Dispositivos cardíacos implantados");
            printf("\n-Valvopatias");
            printf("\n-Infarto Agudo do Miocárdio");
            printf("\n-HIV");
            printf("\n-Doença reumatológica imunomediada sistêmica em atividade ou do sistema imune");
            printf("\n-Câncer");
            printf("\n-Doença renal crônica");
            printf("\n-Hemoglobinopatias graves - Doença falciforme e talassemia maior");
            printf("\n-Doença cerebrovascular");
            printf("\n-Doenças neurológicas crônicas");
            printf("\n-Obesidade mórbida com peso e altura conforme IMC superior a 40.");
            printf("\n-Fibrose cística");
            printf("\n-Síndrome de Down");
            printf("\n-Anemia falciforme");
            printf("\n-Fibrose cística");
            printf("\nDigite 1 para sim e 2 para não.");
            setbuf(stdin,NULL);
            scanf("%d", &Comorbidade);

        //Puxa o calculo da idade do paciente
        int Idade = calculaIdade(Pacientes.dataNascismento.ano,Pacientes.dataNascismento.mes, Pacientes.dataNascismento.dia);


    FILE *pacientesComComorbidade;
        pacientesComComorbidade = fopen("PacientesComComorbidade.txt", "a");

        
		if(Idade>65 || Comorbidade==1){
            printf("O paciente está no grupo de risco!");
            fprintf(pacientesComComorbidade, "\n****Dados do Paciente**** \nNome do Paciente: %s Idade do Paciente: %d CEP: %s\n", Pacientes.nome, Idade, Pacientes.enderecoPaciente.CEP);
         
        
		}
        
        

}
void loginProfissinalDaSaude(void){

    char validaUsuario[50];
    char validaSenha[50];

    typedef struct{
        char usuario[50];
        char senha[50];
    }Profissional;

    Profissional Funcionario1;
        strcpy(Funcionario1.usuario, "Funcionario");
        strcpy(Funcionario1.senha, "saude");

    printf("Digite seu usuário e senha:");
    scanf("\n%s \n%s", validaUsuario, validaSenha);

    while(strcmp(validaUsuario,Funcionario1.usuario)!=0 && strcmp(validaSenha,Funcionario1.senha)!=0){
        printf("\nUsuário ou Senha Inválida!\n");
        printf("Digite seu usuário e senha:");
        scanf("\n%s \n%s", validaUsuario, validaSenha);
    }

    printf("\nSeja bem vindo ao cadastro de paciente!\n");
    PACIENTES_COVID();


}
    int main(void){
	
    setlocale(LC_ALL, "Portuguese");


    int verificarPaciente;

    printf("O paciente foi diagnósticado com COVID-19? (Digite 1 para sim e 2 para não.)");
        setbuf(stdin,NULL);
        scanf("%d", &verificarPaciente);

        switch (verificarPaciente){
            case 1:
                printf("\nRealize o login para ter acesso ao cadastro do paciente\n");
                loginProfissinalDaSaude();
                break;
            case 2:
                printf("\nO cadastro do paciente só é possível se o paciente estiver com COVID-19\n");
                break;
            default:
                printf("\nOpcão inválida!\n");
                break;
        }

}
        
  
