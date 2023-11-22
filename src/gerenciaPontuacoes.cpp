#include "gerenciaPontuacoes.h"


gerenciaPontuacoes::gerenciaPontuacoes()
{
	fundo_salvar = nullptr;
}


gerenciaPontuacoes::~gerenciaPontuacoes()
{
}



gerenciaPontuacoes::Pontuacao::Pontuacao()
{
	pont = -1;
	ID = -1;
}


gerenciaPontuacoes::Pontuacao::~Pontuacao()
{
}


void gerenciaPontuacoes::Pontuacao::setID(const int aID)
{
	ID = aID;
}


const int gerenciaPontuacoes::Pontuacao::getID()
{
	return ID;
}


const float gerenciaPontuacoes::Pontuacao::getPontos()
{
	return pont;
}


void gerenciaPontuacoes::Pontuacao::setPontuacao(const float aPont)
{
	pont = aPont;
}

//	aN = 0 para salvar pontuação da campanha
//	aN = n para salvar pontuação da fase n
void gerenciaPontuacoes::salvarPont(float const pPont, const int aN)
{
	Pontuacao* pScore = new Pontuacao;

	pScore->setID(aN);
	pScore->setPontuacao(pPont);
	pontuacoes.push_back(pScore);
	organiza();
}


void gerenciaPontuacoes::organiza()
{
	organizaIDs();
	organizaPont();
	deleta();
}


void gerenciaPontuacoes::organizaIDs()
{
	bool ordem = false;
	while (!ordem)
	{
		ordem = true;
		for (unsigned int i = 1; i < pontuacoes.size(); i++)
		{
			if (pontuacoes[i]->getID() > pontuacoes[i - 1]->getID())
			{
				Pontuacao* pAux = pontuacoes[i];
				pontuacoes[i] = pontuacoes[i - 1];
				pontuacoes[i - 1] = pAux;
				ordem = false;
			}
		}
	}
}


void gerenciaPontuacoes::organizaPont()
{
	//	organiza as pontuacoes de forma crescente
	//	requer que as pontuacoes com msm IDs estejam juntas
	int posI = 0, posF = 0;
	while (posF < (int)pontuacoes.size())
	{
		int aID = pontuacoes[posI]->getID();
		while (pontuacoes[posF]->getID() == aID)
		{
			posF++;
			if (posF >= (int)pontuacoes.size())
				break;
		}
		posF--;

		if (posI != posF)
		{
			bool ordem = false;
			while (!ordem)
			{
				ordem = true;
				for (int i = posI; i < posF; i++)
				{
					if (pontuacoes[i]->getPontos() > pontuacoes[i + 1]->getPontos())
					{
						ordem = false;
						Pontuacao* pAux = pontuacoes[i];
						pontuacoes[i] = pontuacoes[i + 1];
						pontuacoes[i + 1] = pAux;
					}
				}
			}
		}
		posI = posF + 1;
		posF = posI + 1;
	}
}



void gerenciaPontuacoes::carregaFundo()
{
	al_init_image_addon();
	fundo_salvar = al_load_bitmap("sprites/backgrounds/fundoSalvar.png");
	carregou_fundo = true;
}

void gerenciaPontuacoes::setFonte(ALLEGRO_FONT* const pFont)
{
	if (pFont != nullptr)
		font = pFont;
}


void gerenciaPontuacoes::desenhaPont(const int aID, const int posX, const int posY)
{
	int i;
	for (i = 0; i < (int)pontuacoes.size(); i++)
	{
		if (pontuacoes[i]->getID() == aID)
			break;
		else if (i == pontuacoes.size() - 1)
			return;
	}
	if (i == pontuacoes.size())
		return;
	
	int pos = 1;
	while (pontuacoes[i]->getID() == aID)
	{
		al_draw_textf(font, al_map_rgb(225, 255, 0), posX, posY + (al_get_font_ascent(font)+10)*pos,
			ALLEGRO_ALIGN_LEFT, "%d: %.2f", pos, pontuacoes[i]->getPontos());
		i++;
		pos++;
		if (i == pontuacoes.size() || pos > 10)
			break;
	}
}


void gerenciaPontuacoes::deleta()
{
	int num = 1;
	int size = pontuacoes.size();
	for (int i = 1; i < size; i++)
	{
		if (pontuacoes[i]->getID() == pontuacoes[i-1]->getID())
		{
			num++;
		}
		else
			num = 1;
		if (num > 10)
		{
			Pontuacao* aux = pontuacoes[i];
			pontuacoes.erase(i+pontuacoes.begin());
			delete(aux);
			size--;
			i--;
		}
	}
}


void gerenciaPontuacoes::salvaTxt()
{
	string s = "";
	for (int i = 0; i < (int)pontuacoes.size(); i++)
	{
		s += (pontuacoes[i]->getID()+48);
		s += "-";
		int num = 1000 * pontuacoes[i]->getPontos();
		num /= 10;
		int aux = num;
		int casa = 0;
		while (aux > 0)
		{
			aux /= 10;
			casa++;
		}
		
		int u = 0;
		while (u < casa)
		{
			s += num % 10 + 48;
			num /= 10;
			u++;
		}
		s += "/";
	}
	ofstream outfile;
	outfile.open("pontuacoes.txt", ios::out | ios::trunc);
	outfile << s.c_str();
	outfile.close();
}

gerenciaPontuacoes::Pontuacao::Pontuacao(const int aID, const float aPont)
{
	ID = aID;
	pont = aPont;
}


void gerenciaPontuacoes::carregaTxt()
{
	ifstream infile;
	infile.open("pontuacoes.txt", ios::in);
	if (!infile.is_open())
		return;
	string s = "";
	
	while (!infile.eof())
		s += infile.get();
	bool done = false;
	for (int i = 0; i < (int)s.size(); i++)
	{
		int ID = -1;
		int pot = 1;
		while (s[i] > '9' || s[i] < '0')
		{
			i++;
			if (i >= s.size())
			{
				done = true;
				break;
			}
		}
		if (done)
			break;
		
		while (s[i] <= '9' && s[i] >= '0')
		{
			if (ID == -1)
				ID = 0;
			ID += (s[i] - 48)*pot;
			i++;
			pot *= 10;
			if (i >= s.size())
			{
				done = true;
				break;
			}
		}
		if (done)
			break;
		int pont = -1;
		
		pot = 1;
		while (s[i] > '9' || s[i] < '0')
		{
			i++;
			if (i >= s.size())
			{
				done = true;
				break;
			}
		}
		if (done)
			break;

		while (s[i] <= '9' && s[i] >= '0')
		{
			if (pont == -1)
				pont = 0;
			pont += (s[i] - 48)*pot;
			i++;
			pot *= 10;
			if (i >= s.size())
				break;
		}

		float tempo = pont;
		if (ID != -1 && pont != -1)
		{
			Pontuacao* pont = new Pontuacao(ID, tempo / 100);
			pontuacoes.push_back(pont);
		}
	}
	organiza();
}
