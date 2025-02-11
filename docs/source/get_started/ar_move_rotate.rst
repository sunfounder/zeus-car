.. note:: 

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Bénéficiez de l’aide de notre communauté et de notre équipe pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

3. Déplacement et Rotation
==============================

Dans ce projet, le Zeus Car peut inclure des paramètres de rotation pour tourner sur place ou se déplacer en arc de cercle.

**Comment procéder ?**

#. La ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lorsque vous téléversez du code, vous devez d'abord déconnecter la ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Ouvrez le fichier ``3_rotate_and_move.ino`` sous le chemin ``zeus-car-main\examples\3_rotate_and_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/bf0dfe1b-18c1-4a45-bd38-a9a8e671d66a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Une fois le code téléversé avec succès, mettez l'interrupteur d’alimentation sur ON pour démarrer le Zeus Car. Il tournera d'abord à gauche puis à droite pour revenir à sa position initiale. Ensuite, le véhicule effectuera un mouvement en arc de cercle, avec un angle de rotation qui diminuera progressivement jusqu'à tourner sur lui-même.



**Comment cela fonctionne-t-il ?**

Un paramètre de puissance de rotation ``rot`` est ajouté à la fonction de déplacement ``carMove()`` du Zeus Car.

.. code-block::

    void carMove(int16_t angle, int8_t power, int8_t rot)

* ``angle`` : La direction dans laquelle vous voulez que le véhicule se déplace. L'avant du véhicule est défini comme 0 degré et l'angle augmente dans le sens antihoraire.
* ``power`` : La puissance du mouvement, avec une plage de -100 % à 100 %. Une valeur positive fait avancer le véhicule, tandis qu'une valeur négative le fait reculer.
* ``rot`` : La puissance de rotation, avec une plage de -100 % à 100 %. Une valeur positive entraîne une rotation dans le sens antihoraire, et une valeur négative dans le sens horaire.

Si ``power`` est à 0 et que ``rot`` n'est pas à 0, le Zeus Car tournera sur place. Plus la puissance de rotation est élevée, plus la vitesse de rotation est rapide. Une valeur positive entraîne une rotation antihoraire et une valeur négative une rotation horaire.

Si ``power`` n'est pas 0, le Zeus Car effectuera un déplacement en arc de cercle. L'angle de courbure augmentera avec la valeur de ``rot`` et, si cette valeur est suffisamment élevée, le véhicule finira par tourner sur lui-même.
