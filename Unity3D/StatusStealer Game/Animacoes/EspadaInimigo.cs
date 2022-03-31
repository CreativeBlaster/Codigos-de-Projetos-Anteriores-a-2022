using UnityEngine;
using System.Collections;

public class EspadaInimigo : MonoBehaviour {

	// Use this for initialization
	void Start () {

        transform.SetParent(GameObject.FindGameObjectWithTag("Inimigo").transform);

    }
		
}
