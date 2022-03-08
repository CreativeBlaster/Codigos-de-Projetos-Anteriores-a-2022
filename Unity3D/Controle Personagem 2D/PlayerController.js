#pragma strict

var idleState : int = 0;

function Start () {
   
    //imagem.GetComponent.<SpriteRenderer>().sortingOrder = 3;
}

function Update () {
    var vertical = Input.GetAxis("Vertical");
    var horizontal = Input.GetAxis("Horizontal");
 
    if (vertical > 0)
    {
        Debug.Log("CIMA");
       GetComponent.<Animator>().SetInteger("Direction", 2);
      GetComponent.<Animator>().speed = 2;
       
       
      
    }
    else if (vertical < 0)
    {
    	 Debug.Log("BAIXO");
       GetComponent.<Animator>().SetInteger("Direction", 0);
      GetComponent.<Animator>().speed = 2;
      
              
    }
    else if (horizontal > 0)
    {
    	Debug.Log("DIREITA");
        GetComponent.<Animator>().SetInteger("Direction", 3);
       GetComponent.<Animator>().speed = 2;
       
        
        
    }
    else if (horizontal < 0)
    {
    	Debug.Log("ESQUERDA");
        GetComponent.<Animator>().SetInteger("Direction", 1);
        GetComponent.<Animator>().speed = 2;
    	
    	
    }
    else if(horizontal == 0 && vertical == 0){
    GetComponent.<Animator>().speed = 0;
   
   
    }
}

 