#include "../include/Knight.hpp"

/**@brief Método construtor do Cavalo
*
*Parâmetros: booleano indicando se a peça é branca e posições X e Y da peça no tabuleiro
*
*Tratamento de Erros: Não há tratamento de erros
*
*Descrição: O método atribui um nome, uma cor, um valor, 
*posições X e Y e atribuí à peça o estado de vida
*
*Assertivas de entrada: booleano que indica se a peça é branca e duas posições 
*X e Y que indicam a posição da peça no tabuleiro
*
*Requisitos: O método deve setar um nome, uma posição, 
*uma cor um estado de vida e um valor à peça
*
*Hipóteses: O nome da peça deve ser do tipo PieceName e as posições 
*X e Y devem pertencer ao tabuleiro
*
*Assertivas de saida: Não há assertivas de saída
*
*Interface explicita: bool isWhite, int position_X, int position_Y
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: O método constrói a peça 
*King atribuindo características básicas ao objeto da classe
*
*/

Knight::Knight(bool isWhite, int position_X, int position_Y)
{
  this->name = PieceName::Knight;
  this->isWhite = isWhite;
  this->position_X = position_X;
  this->position_Y = position_Y;
  isAlive = true;
  PieceValue = 3;
}

Knight::~Knight()
{
}

/**@brief Função que valida se o movimento do Cavalo é possível
*
*Parâmetros: dois inteiros que indicam a posição final da peça
*
*Tratamento de Erros: É verificado se as posições inseridas nos 
*parâmetros pertencem ao tabuleiro
*
*Descrição: O método verifica se a posição final pertence ao tabuleiro, 
*e em seguida verifica se o movimento é possível para o Cavalo e se a 
*posição final é diferente da posição em que ele já está
*
*Assertivas de entrada: dois inteiros que indicam a posição final da peça no tabuleiro
*
*Requisitos: As posições dos parâmetros devem pertencer ao tabuleiro 
*e o Cavalo deve poder se mover até lá
*
*Hipóteses: Se o movimento do Cavalo for possível, o método deve retornar um booleano true, 
*caso contrário deve retornar um booleano false
*
*Assertivas de saida: bool true or bool false
*
*Interface explicita: int FinalPosition_X, int FinalPosition_Y
*
*Interface implicita: Não há interface implícita
*
*Contrato na especificação: Se o movimento do Cavalo for possível, o método deve retornar um booleano true, 
*caso contrário deve retornar um booleano false
*
*/

bool Knight::IsMovementPossible(int FinalPosition_X, int FinalPosition_Y)
{
  if(FinalPosition_X >= 0 && FinalPosition_Y >= 0 && FinalPosition_X < 8 && FinalPosition_Y < 8 && isAlive) //Peça tem que estar no tabuleiro e estar viva
  {
    int movement_x = abs(FinalPosition_X - position_X);
    int movement_y = abs(FinalPosition_Y - position_Y);

    if((movement_x == 1 && movement_y == 2) || (movement_x == 2 && movement_y == 1)) //Movimento em 'L' e posição final diferente da inicial
    {
      return true;
    }
  }

  return false;
}
