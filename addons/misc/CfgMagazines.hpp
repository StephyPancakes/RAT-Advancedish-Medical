class CfgMagazines {
    class CA_Magazine;
    
    class rat_Bubble_Wrap: CA_Magazine {
        scope = 2;
        author = "Miss Heda";
        displayName = CSTRING(Bubble_Wrap_Display);
        descriptionShort = CSTRING(Bubble_Wrap_Desc);
        picture = QPATHTOF(ui\Bubble_Wrap_Item.paa);
        
        ammo = "";
        count = 50;
        initSpeed = 0;
        tracersEvery = 0;
        lastRoundsTracer = 0;
        mass = 0.1;
    };
};
