using UnityEngine;
using System.Collections;

public class Morte : MonoBehaviour {

	private float smooth = 10.0F;//serve para "amortecer" a movimentação
    
    private float direcao;//serve para definir a direção da rotacao atual

   // private float repeticao;//usado para limitar repeticao para apenas 1 loop
    private bool play;// serve como botão: true - liga , false - desliga
    private float controle;//serve como controle para esperar que se REaperte o play(o próximo true de : true-false-true)
    //public float limite;// LImite para repetição
    private float max;// pois o maximo em transform é diferente do máximo no Quaternion
    private float maxZ; // comparacao do transforma para rotação em Z
	private bool queda; //Abilita a queda
	private float speed;// Velocidade da queda


	// Use this for initialization
	void Start () {
			
            speed = -0.2F;//no caso altera a traslacao no eixo X (rotaciona em z, seu negativo vira para baixo)
               
		queda = true;
        direcao = 1.0F;
        controle = 0.0F;
            
            max = 90.0F;
            maxZ = 0.90F;
        
          

	}
	
	// Update is called once per frame
	void Update () {
	
		 // CONTROLE para fazer repetir apenas quando mandado
        if (controle == 0.0F)
        { // FORMULA GERAL
            if (play)// QUANDO APERTAR BOTÃO
            { 
            
               //Variavel aqui ;// VARIAVEL QUE QUERO    ALTERAR  
                controle++;
            }
                 
        }

        if (controle >= 1.0F)//TUDO SÓ FUNCIONARA SE O BOTAO PLAY TIVER SIDO APERTADO
        {

            //verificar direcao e deninir sentido de direcao 
            if (direcao == 1.0F)//anti-horário -direita
            {
                //limite de rotacao e definicao de retorno
                if (transform.rotation.z >= maxZ)//chegou no maximo, Pare!
                {

                    Quaternion target = Quaternion.Euler(0, 0, 0);//x,y,z
                    transform.rotation = Quaternion.Slerp(transform.rotation, target, 0);
                    
                }
                if (transform.rotation.z < maxZ)//não chegou no máximo(antihorário) manda chegar
                {

                    Quaternion target = Quaternion.Euler(0, 0, max);//x,y,z
                    transform.rotation = Quaternion.Slerp(transform.rotation, target, Time.deltaTime * smooth);
                }
            }

            if (queda)// Confuso EU MUDO O EIXO X, POIS O MOVIMENTO É RELATIVO, MAS VERIFICO O MÁXIMO EM Y
        {
            //limite de rotacao e definicao de retorno
            if (transform.position.y <= -1.20F)//chegou no máximo - manda Parar
            {
                transform.Translate(0,0,0);
                queda = false;
                play = false;

            }
            if (transform.position.y > -1.2F)//não chegou no máximo - manda descer
            {
                transform.Translate(speed * Time.deltaTime, 0, 0);
               
            }
        }

        if (!play)
            {
                controle = 0.0F;
                queda = true;
                direcao = 1.0F;
            }
            
        }


	}

    //FAÇO ESSES METHODOS POIS É NECESSÁRIO COMPARTILHAR VARIAVEIS COM SEGURANÇA
    public void SetPlay(bool roda){
        this.play = roda;
        
    }
    public bool GetPlay(){
        return play;
    }

}
