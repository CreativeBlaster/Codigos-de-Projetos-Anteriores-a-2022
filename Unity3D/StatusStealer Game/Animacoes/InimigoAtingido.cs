using UnityEngine;
using System.Collections;

public class InimigoAtingido : MonoBehaviour
{


    private float smooth = 10.0F;//serve para "amortecer" a movimentação

    private float direcao;//serve para definir a direção da rotacao atual

    private float repeticao;//usado para limitar repeticao para apenas 1 loop
    private bool play;// serve como botão: true - liga , false - desliga
    private float controle;//serve como controle para esperar que se REaperte o play(o próximo true de : true-false-true)
    //public float limite;// LImite para repetição
    private bool fim;//FOI NECESSÁRIO ADICIONAR ESSA VAR PARA REGULAR A REPETICAO DO ANIMACAO

    private float min;
    private float max;
    private float maxZ;


    // Use this for initialization
    void Start()
    {

        //limite = 1.0F;
        direcao = 1.0F;
        repeticao = 1.0F;
        controle = 0.0F;

            min = 30.0F;
            max = -50.0F;
            maxZ = -0.30F;

         fim = false;


    }

    // Update is called once per frame
    void Update()
    {
        // CONTROLE para fazer repetir apenas quando mandado
        if (controle == 0.0F)
        { // FORMULA GERAL
            if (play)// QUANDO APERTAR BOTÃO
            {

                repeticao = 0.0F; // VARIAVEL QUE QUERO    ALTERAR  
                controle++;
            }

        }

        if (controle >= 1.0F)//TUDO SÓ FUNCIONARA SE O BOTAO PLAY TIVER SIDO APERTADO
        {

            //verificar direcao e deninir sentido de direcao 
            if (direcao == 1.0F)//horário -direita
            {
                //limite de rotacao e definicao de retorno
                if (transform.rotation.z <= maxZ)//chegou no maximo, muda sentido e manda pra baixo
                {

                    Quaternion target = Quaternion.Euler(0, 0, min);//x,y,z
                    transform.rotation = Quaternion.Slerp(transform.rotation, target, Time.deltaTime * smooth);
                    direcao = -1.0F;
                    fim = true;
                }
                if (transform.rotation.z > maxZ)//não chegou no máximo(antihorário) manda chegar
                {

                    Quaternion target = Quaternion.Euler(0, 0, max);//x,y,z
                    transform.rotation = Quaternion.Slerp(transform.rotation, target, Time.deltaTime * smooth);
                }
            }

            if (direcao == -1.0F)//antihorário ,esquerda
            {

                if (transform.rotation.z < -0.0)//se ->esquerda : e ele nao chegou no minimo, manda girar horario
                {

                    Quaternion target = Quaternion.Euler(0, 0, min);//x,y,z
                    transform.rotation = Quaternion.Slerp(transform.rotation, target, Time.deltaTime * smooth);
                }

                if (transform.rotation.z >= -0.0 && !fim)  // começa aqui se PLay ativado - GIra SOBE
                {

                    Quaternion target = Quaternion.Euler(0, 0, max);//x,y,z
                    transform.rotation = Quaternion.Slerp(transform.rotation, target, Time.deltaTime * smooth);
                    direcao = 1.0F;

                }
                if (transform.rotation.z >= -0.0 && fim)//termina aqui  Se play desativado pára
                {

                    Quaternion target = Quaternion.Euler(0, 0, 0);
                    transform.rotation = target;
                    repeticao++;
                    play = false;
                }
            }

            if (!play && repeticao == 1.0F)
            {
                controle = 0.0F;
                 fim = false;
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
