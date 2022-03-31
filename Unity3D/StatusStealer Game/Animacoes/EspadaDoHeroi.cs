using UnityEngine;
using System.Collections;

public class EspadaDoHeroi : MonoBehaviour
{
    //public GameObject Espada1;
    // Use this for initialization
    void Start()
    {
        transform.SetParent(GameObject.FindGameObjectWithTag("Heroi").transform);
        //Espada1 = GameObject.FindGameObjectWithTag("Espada");
       // transform.SetParent(GameObject.FindGameObjectWithTag("Heroi").transform);

    }

    
}
