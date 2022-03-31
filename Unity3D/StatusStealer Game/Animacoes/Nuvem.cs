using UnityEngine;
using System.Collections;

public class Nuvem : MonoBehaviour {
    private float velocidade;
    private Vector3 myPosition;
    private Vector3 positionNow;
    private float diferenca;

    // Use this for initialization
    void Start () {
        //pega a posição inicial
        myPosition = transform.position;
        //verifica qual tipo de objeto pela tag
        if (gameObject.CompareTag("Nuvem1")) {
            velocidade = 0.02F;
        }
        if (gameObject.CompareTag("Nuvem2"))
        {
            velocidade = 0.04F;
        }
        if (gameObject.CompareTag("Nuvem3"))
        {
            velocidade = 0.08F;
        }
    }
	
	// Update is called once per frame
	void Update () {
        //movimentação
        transform.Translate(Time.deltaTime * (-velocidade), 0,0 );
        //pega a posição atual
        positionNow = transform.position;
        //calculo da diferença para comparação if 1.6 em x
        diferenca = myPosition.x - positionNow.x ;
       
         if (diferenca >= 2){
            transform.position = myPosition;
        } 
    }
}
