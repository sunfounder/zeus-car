.. note:: 

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Bénéficiez de l’aide de notre communauté et de notre équipe pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

4. Drift
======================

Dans ce projet, vous apprendrez à faire drifter le Zeus Car.

.. image:: img/zeus_drift_left.jpg

**Comment procéder ?**

#. La ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lorsque vous téléversez du code, vous devez d'abord déconnecter la ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Ouvrez le fichier ``4_drift.ino`` sous le chemin ``zeus-car-main\examples\4_drift``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/9ca66dad-7258-4868-a8a4-3bd512bacd72/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Une fois le code téléversé avec succès, mettez l'interrupteur d’alimentation sur ON pour démarrer le Zeus Car.
#. Le Zeus Car avancera pendant 0,5 seconde, puis effectuera un drift de 90 degrés vers la gauche, et ainsi de suite. Vous pouvez essayer de modifier la valeur 45 (rot) par une autre valeur ou un nombre négatif pour observer comment l’angle et la direction du drift changent.


**Comment ça fonctionne ?**

Le drift du Zeus Car est réalisé en ajoutant le paramètre ``drift`` à la fonction de mouvement ``carMove()``.

.. code-block::

    void carMove(int16_t angle, int8_t power, int8_t rot, bool drift)

* ``angle`` : La direction dans laquelle vous souhaitez déplacer la voiture. L'avant du véhicule est défini comme 0 degré, et l'angle augmente dans le sens antihoraire.
* ``power`` : La puissance du déplacement, comprise entre -100 % et 100 %. Lorsque la valeur est positive, la voiture avance ; lorsqu'elle est négative, elle recule.
* ``rot`` : La puissance de rotation, comprise entre -100 % et 100 %. Lorsque la valeur est positive, la voiture tourne dans le sens antihoraire, et inversement.
* ``drift`` : Par défaut false. Lorsqu'il est true, le mode drift est activé.

Ainsi, différentes valeurs de ``power`` et ``rot`` modifieront l'angle et la direction du drift du Zeus Car.
