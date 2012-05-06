/*global clearInterval: false, clearTimeout: false, document: false, event: false, frames: false, history: false, Image: false, location: false, name: false, navigator: false, Option: false, parent: false, screen: false, setInterval: false, setTimeout: false, window: false, XMLHttpRequest: false, $: false, alert: false */


var testFct, drawMyImageFct, renderingLoop, imgFront;

var FORCEBRUTE = (function () {
    "use strict";

    var myMovingElement, myImagesList, counter, preloadImages, preloadImagesCallback, myImagesLoaded;

    myMovingElement = ["../images/bateau/0001.png"];

    myImagesLoaded = [];
    myImagesList = [];

  
    for (counter = 1; counter < 10; counter += 1) {
        myImagesList.push("../images/water/000" + counter + ".jpg");
    }
    
    for (counter = 10; counter < 100; counter += 1) {
        myImagesList.push("../images/water/00" + counter + ".jpg");
    }

    for (counter = 100; counter <= 300; counter += 1) {
        myImagesList.push("../images/water/0" + counter + ".jpg");
    }


//    myImagesList = ["../images/water/0001.jpg",
//            "../images/water/0002.jpg",
//            "../images/water/0003.jpg",
//            "../images/water/0004.jpg",
//            "../images/water/0005.jpg",
//            "../images/water/0006.jpg",
//            "../images/water/0007.jpg",
//            "../images/water/0008.jpg",
//            "../images/water/0009.jpg",
//            "../images/water/0010.jpg",
//            "../images/water/0011.jpg",
//            "../images/water/0012.jpg",
//            "../images/water/0013.jpg",
//            "../images/water/0014.jpg",
//            "../images/water/0015.jpg",
//            "../images/water/0016.jpg",
//            "../images/water/0017.jpg",
//            "../images/water/0018.jpg",
//            "../images/water/0019.jpg",
//            "../images/water/0020.jpg",
//            "../images/water/0021.jpg",
//            "../images/water/0022.jpg",
//            "../images/water/0023.jpg",
//            "../images/water/0024.jpg",
//            "../images/water/0025.jpg",
//            "../images/water/0026.jpg",
//            "../images/water/0027.jpg",
//            "../images/water/0028.jpg",
//            "../images/water/0029.jpg" ];
//
    preloadImagesCallback = function (imageIndex, img) {
        myImagesLoaded[imageIndex.toString()] = img;

        if (myImagesLoaded.length === 300) {
            // Loading complete
            renderingLoop(0);
        }

    };

    preloadImages = function () {
        //var canvas = document.getElementById('canvas'), ctx, img, newIndex, imgFront;
        //ctx = canvas.getContext('2d');
        //ctx.globalAlpha = 0;
        
        var img, counter = 0;

        imgFront = new Image();
        imgFront.src = myMovingElement[0];

        for (counter = 1; counter <= myImagesList.length; counter += 1) {
            img = new Image();
            img.onload = preloadImagesCallback(counter - 1, img);
            img.src = myImagesList[counter - 1];
        }
    };

    renderingLoop = function (imageIndex) {

        var canvas = document.getElementById('canvas'), ctx, img, newIndex;
        ctx = canvas.getContext('2d');
        //ctx.globalAlpha = 0;
        
        
        img = myImagesLoaded[imageIndex];

        try {
            ctx.drawImage(img, 0, 0);
            ctx.drawImage(imgFront, 0, 0);
        } catch (exception) {
            //debugger;
        };

        newIndex = (imageIndex + 1) % (myImagesLoaded.length - 1);
        setTimeout('renderingLoop(' + newIndex + ')', 50);
    };

    return {
        RenderImages: function () {
            preloadImages();
        }
    };
}());




