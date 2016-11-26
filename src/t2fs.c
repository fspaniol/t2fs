#include "../include/t2fs.h"
#include "../include/apidisk.h"
#include "../include/bitmap2.h"
#include <stdio.h>

#ifndef __LIBT2FS___
#define __LIBT2FS___
#define	SECTOR_SIZE	256
#define TYPEVAL_INVALIDO    0x00
#define TYPEVAL_REGULAR     0x01
#define TYPEVAL_DIRETORIO   0x02

/* Valores */
#define T2FS_SUCCESS 0
#define T2FS_ERROR -1

typedef int FILE2;
typedef int DIR2;

typedef unsigned char BYTE;
typedef unsigned short int WORD;
typedef unsigned int DWORD;

/* Estruturas */
typedef struct t2fs_superbloco SUPERBLOCK;
typedef struct t2fs_inode      INODE;
typedef struct t2fs_record     RECORD;

//globais
FS_INFORMATION file_system_info;

/*-----------------------------------------------------------------------------
 FunÁ„o: Usada para identificar os desenvolvedores do T2FS.
	Essa funÁ„o copia um string de identificaÁ„o para o ponteiro indicado por "name".
	Essa cÛpia n„o pode exceder o tamanho do buffer, informado pelo par‚metro "size".
	O string deve ser formado apenas por caracteres ASCII (Valores entre 0x20 e 0x7A) e terminado por ë\0í.
	O string deve conter o nome e n˙mero do cart„o dos participantes do grupo.
 
 Entra:	name -> buffer onde colocar o string de identificaÁ„o.
	size -> tamanho do buffer "name" (n˙mero m·ximo de bytes a serem copiados).
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna "0" (zero).
	Em caso de erro, ser· retornado um valor diferente de zero.
 -----------------------------------------------------------------------------*/
int identify2 (char *name, int size){
    char participantes[] = "Nome: Fernando Luis Spaniol Cartao: 228343 \n Nome: Filipe Joner Cartao: 208840 \n Nome: Mateus Claudino Bica Cartao: 164383  \n";
    int tamanho = sizeof(participantes);
    int x = 0;
    
    if(size <= 0){
        printf("Erro! Size eh negativo. \n");
        return -1;
    }
    
    while (x < size && x<tamanho){
        *name = participantes[x];
        name++;
        x++;
    }
    
    return 0;
}


/*-----------------------------------------------------------------------------
 FunÁ„o: Criar um novo arquivo.
	O nome desse novo arquivo È aquele informado pelo par‚metro "filename".
	O contador de posiÁ„o do arquivo (current pointer) deve ser colocado na posiÁ„o zero.
	Caso j· exista um arquivo ou diretÛrio com o mesmo nome, a funÁ„o dever· retornar um erro de criaÁ„o.
	A funÁ„o deve retornar o identificador (handle) do arquivo.
	Esse handle ser· usado em chamadas posteriores do sistema de arquivo para fins de manipulaÁ„o do arquivo criado.
 
 Entra:	filename -> nome do arquivo a ser criado.
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna o handle do arquivo (n˙mero positivo).
	Em caso de erro, deve ser retornado um valor negativo.
 -----------------------------------------------------------------------------*/
FILE2 create2 (char *filename){
    return -1;
}


/*-----------------------------------------------------------------------------
 FunÁ„o:	Apagar um arquivo do disco.
	O nome do arquivo a ser apagado È aquele informado pelo par‚metro "filename".
 
 Entra:	filename -> nome do arquivo a ser apagado.
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna "0" (zero).
	Em caso de erro, ser· retornado um valor diferente de zero.
 -----------------------------------------------------------------------------*/
int delete2 (char *filename){
    return -1;
}


/*-----------------------------------------------------------------------------
 FunÁ„o:	Abre um arquivo existente no disco.
	O nome desse novo arquivo È aquele informado pelo par‚metro "filename".
	Ao abrir um arquivo, o contador de posiÁ„o do arquivo (current pointer) deve ser colocado na posiÁ„o zero.
	A funÁ„o deve retornar o identificador (handle) do arquivo.
	Esse handle ser· usado em chamadas posteriores do sistema de arquivo para fins de manipulaÁ„o do arquivo criado.
	Todos os arquivos abertos por esta chamada s„o abertos em leitura e em escrita.
	O ponto em que a leitura, ou escrita, ser· realizada È fornecido pelo valor current_pointer (ver funÁ„o seek2).
 
 Entra:	filename -> nome do arquivo a ser apagado.
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna o handle do arquivo (n˙mero positivo)
	Em caso de erro, deve ser retornado um valor negativo
 -----------------------------------------------------------------------------*/
FILE2 open2 (char *filename){
    return -1;
}


/*-----------------------------------------------------------------------------
 FunÁ„o:	Fecha o arquivo identificado pelo par‚metro "handle".
 
 Entra:	handle -> identificador do arquivo a ser fechado
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna "0" (zero).
	Em caso de erro, ser· retornado um valor diferente de zero.
 -----------------------------------------------------------------------------*/
int close2 (FILE2 handle){
    return -1;
}


/*-----------------------------------------------------------------------------
 FunÁ„o:	Realiza a leitura de "size" bytes do arquivo identificado por "handle".
	Os bytes lidos s„o colocados na ·rea apontada por "buffer".
	ApÛs a leitura, o contador de posiÁ„o (current pointer) deve ser ajustado para o byte seguinte ao ˙ltimo lido.
 
 Entra:	handle -> identificador do arquivo a ser lido
	buffer -> buffer onde colocar os bytes lidos do arquivo
	size -> n˙mero de bytes a serem lidos
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna o n˙mero de bytes lidos.
	Se o valor retornado for menor do que "size", ent„o o contador de posiÁ„o atingiu o final do arquivo.
	Em caso de erro, ser· retornado um valor negativo.
 -----------------------------------------------------------------------------*/
int read2 (FILE2 handle, char *buffer, int size){
    return -1;
}


/*-----------------------------------------------------------------------------
 FunÁ„o:	Realiza a escrita de "size" bytes no arquivo identificado por "handle".
	Os bytes a serem escritos est„o na ·rea apontada por "buffer".
	ApÛs a escrita, o contador de posiÁ„o (current pointer) deve ser ajustado para o byte seguinte ao ˙ltimo escrito.
 
 Entra:	handle -> identificador do arquivo a ser escrito
	buffer -> buffer de onde pegar os bytes a serem escritos no arquivo
	size -> n˙mero de bytes a serem escritos
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna o n˙mero de bytes efetivamente escritos.
	Em caso de erro, ser· retornado um valor negativo.
 -----------------------------------------------------------------------------*/
int write2 (FILE2 handle, char *buffer, int size){
    return -1;
}


/*-----------------------------------------------------------------------------
 
 
 FunÁ„o:	FunÁ„o usada para truncar um arquivo.
	Remove do arquivo todos os bytes a partir da posiÁ„o atual do contador de posiÁ„o (current pointer)
	Todos os bytes desde a posiÁ„o indicada pelo current pointer atÈ o final do arquivo s„o removidos do arquivo.
 
 Entra:	handle -> identificador do arquivo a ser truncado
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna "0" (zero).
	Em caso de erro, ser· retornado um valor diferente de zero.
 -----------------------------------------------------------------------------*/
int truncate2 (FILE2 handle){
    return -1;
}


/*-----------------------------------------------------------------------------
 FunÁ„o:	Reposiciona o contador de posiÁıes (current pointer) do arquivo identificado por "handle".
	A nova posiÁ„o È determinada pelo par‚metro "offset".
	O par‚metro "offset" corresponde ao deslocamento, em bytes, contados a partir do inÌcio do arquivo.
	Se o valor de "offset" for "-1", o current_pointer dever· ser posicionado no byte seguinte ao final do arquivo,
 Isso È ˙til para permitir que novos dados sejam adicionados no final de um arquivo j· existente.
 
 Entra:	handle -> identificador do arquivo a ser escrito
	offset -> deslocamento, em bytes, onde posicionar o "current pointer".
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna "0" (zero).
	Em caso de erro, ser· retornado um valor diferente de zero.
 -----------------------------------------------------------------------------*/
int seek2 (FILE2 handle, DWORD offset){
    return -1;
}


/*-----------------------------------------------------------------------------
 FunÁ„o:	Criar um novo diretÛrio.
	O caminho desse novo diretÛrio È aquele informado pelo par‚metro "pathname".
 O caminho pode ser ser absoluto ou relativo.
	A criaÁ„o de um novo subdiretÛrio deve ser acompanhada pela criaÁ„o, autom·tica, das entradas "." e ".."
	A entrada "." corresponde ao descritor do subdiretÛrio recÈm criado
	A entrada ".." corresponde ‡ entrada de seu diretÛrio pai.
	S„o considerados erros de criaÁ„o quaisquer situaÁıes em que o diretÛrio n„o possa ser criado.
 Isso inclui a existÍncia de um arquivo ou diretÛrio com o mesmo "pathname".
 
 Entra:	pathname -> caminho do diretÛrio a ser criado
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna "0" (zero).
	Em caso de erro, ser· retornado um valor diferente de zero.
 -----------------------------------------------------------------------------*/
int mkdir2 (char *pathname){
	 int status_retorno = 0;

    //Verifica se a biblioteca já foi inicializada.
    //if(fs_first_call)
    //{
    //    initialize_all();
    //    fs_first_call = FALSE;
    //}

    //Checa se o nome do arquivo é sintaticamente válido.
    //BOOL name_is_valid;
    check_filename_is_valid(pathname, &name_is_valid);

    if(name_is_valid)
    {
        //Obtém o nome do arquivo em si.
        char main_name[MAX_FILE_NAME_SIZE];
        get_record_name_from_path_string(pathname, main_name);

        //Verifica se o tamanho do nome está nos limites corretos.
        if(strlen(pathname) < MAX_FILE_NAME_SIZE && strlen(main_name) < T2_GROUP_ID_STRING_SIZE)
        {
            char path_to_create[MAX_FILE_NAME_SIZE];
            strcpy(path_to_create, pathname);

            //Cria o diretório.
            ret_status = alloc_record_by_path(path_to_create, TYPEVAL_DIRETORIO, NULL);

            if(ret_status != 0)
                ret_status = T2_ERROR;
        }

        else
            ret_status = T2_ERROR;
    }

    else
        ret_status = T2_ERROR;

    return ret_status;
    return -1;
}


/*-----------------------------------------------------------------------------
 FunÁ„o:	Apagar um subdiretÛrio do disco.
	O caminho do diretÛrio a ser apagado È aquele informado pelo par‚metro "pathname".
	S„o considerados erros quaisquer situaÁıes que impeÁam a operaÁ„o.
 Isso inclui:
 (a) o diretÛrio a ser removido n„o est· vazio;
 (b) "pathname" n„o existente;
 (c) algum dos componentes do "pathname" n„o existe (caminho inv·lido);
 (d) o "pathname" indicado n„o È um arquivo;
 (e) o "pathname" indica os diretÛrios "." ou "..".
 
 Entra:	pathname -> caminho do diretÛrio a ser criado
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna "0" (zero).
	Em caso de erro, ser· retornado um valor diferente de zero.
 -----------------------------------------------------------------------------*/
int rmdir2 (char *pathname){
    return -1;
}


/*-----------------------------------------------------------------------------
 FunÁ„o:	Abre um diretÛrio existente no disco.
	O caminho desse diretÛrio È aquele informado pelo par‚metro "pathname".
	Se a operaÁ„o foi realizada com sucesso, a funÁ„o:
 (a) deve retornar o identificador (handle) do diretÛrio
 (b) deve posicionar o ponteiro de entradas (current entry) na primeira posiÁ„o v·lida do diretÛrio "pathname".
	O handle retornado ser· usado em chamadas posteriores do sistema de arquivo para fins de manipulaÁ„o do diretÛrio.
 
 Entra:	pathname -> caminho do diretÛrio a ser aberto
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna o identificador do diretÛrio (handle).
	Em caso de erro, ser· retornado um valor negativo.
 -----------------------------------------------------------------------------*/
DIR2 opendir2 (char *pathname){
    return -1;
}


/*-----------------------------------------------------------------------------
 FunÁ„o:	Realiza a leitura das entradas do diretÛrio identificado por "handle".
	A cada chamada da funÁ„o È lida a entrada seguinte do diretÛrio representado pelo identificador "handle".
	Algumas das informaÁıes dessas entradas devem ser colocadas no par‚metro "dentry".
	ApÛs realizada a leitura de uma entrada, o ponteiro de entradas (current entry) deve ser ajustado para a prÛxima entrada v·lida, seguinte ‡ ˙ltima lida.
	S„o considerados erros:
 (a) qualquer situaÁ„o que impeÁa a realizaÁ„o da operaÁ„o
 (b) tÈrmino das entradas v·lidas do diretÛrio identificado por "handle".
 
 Entra:	handle -> identificador do diretÛrio cujas entradas deseja-se ler.
	dentry -> estrutura de dados onde a funÁ„o coloca as informaÁıes da entrada lida.
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna "0" (zero).
	Em caso de erro, ser· retornado um valor diferente de zero ( e "dentry" n„o ser· v·lido)
 -----------------------------------------------------------------------------*/
int readdir2 (DIR2 handle, DIRENT2 *dentry){
    return -1;
}


/*-----------------------------------------------------------------------------
 FunÁ„o:	Fecha o diretÛrio identificado pelo par‚metro "handle".
 
 Entra:	handle -> identificador do diretÛrio que se deseja fechar (encerrar a operaÁ„o).
 
 SaÌda:	Se a operaÁ„o foi realizada com sucesso, a funÁ„o retorna "0" (zero).
	Em caso de erro, ser· retornado um valor diferente de zero.
 -----------------------------------------------------------------------------*/
int closedir2 (DIR2 handle){
    return -1;
}


int inicializa_inf_disco (){

	local_status = 0;

	SUPERBLOCK file_system_superblock;

	//Lê o superbloco e inicializa variáveis das informações contidas nele.
    char* buffer_superbloco = (char*) malloc(SECTOR_SIZE);

    //se o buffer inicializou corretamente
    if(buffer_superbloco != NULL)
    {
    	if(!read_sector(0, buffer_superbloco)) //le o setor 0, superbloco do disco retorna != 0 
        {
        	//copia para o file_system_superblock o buffer inicializado
        	memcpy(&file_system_superblock, superblock_buffer, sizeof(SUPERBLOCK));

	        file_system_info.numSetoresSuperBloco = file_system_superblock.superblockSize;
	        file_system_info.numSetoresBitmapDeBlocos = file_system_superblock.freeBlocksBitmapSize;
	        file_system_info.numSetoresBitmapDeInodes = file_system_superblock.freeInodeBitmapSize;
	        file_system_info.numSetoresUmBlocksize = file_system_superblock.blockSize;
	        file_system_info.numSetoresTotalT2FS = file_system_superblock.diskSize;
	        file_system_info.numSetoresInodes = file_system_superblock.inodeAreaSize;

        } else {
        	local_status = T2FS_ERROR;
        }

        free(buffer_superbloco);
    } else {
    	local_status = T2FS_ERROR;
    }

    return local_status;

}

#endif
