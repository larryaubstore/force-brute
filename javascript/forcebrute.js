/*global clearInterval: false, clearTimeout: false, document: false, event: false, frames: false, history: false, Image: false, location: false, name: false, navigator: false, Option: false, parent: false, screen: false, setInterval: false, setTimeout: false, window: false, XMLHttpRequest: false, $: false, alert: false */


var testFct, drawMyImageFct;/*, renderingLoop, imgFront;*/

var FORCEBRUTE = (function () {
    "use strict";

    var myMovingElement, myImagesList, counter, preloadImages,
        preloadImagesCallback, myImagesLoaded, renderingLoop,
        boatYPosition, imgFront, imgGrid, myGrid, myImagesListGrid,
        myRedSquare, imgRedSquare, bindEvents,
        redSquareXPos, redSquareYPos;

    myMovingElement = ["../images/bateau/0001-min.png"];
    myGrid = ["../images/grid/v3/0002.png"];
    myRedSquare = ["../images/redsquare/0003.png"];

    myImagesLoaded = [];
    myImagesList = [];
    myImagesListGrid = [];
    boatYPosition = 500;

    // Position du carré rouge
    redSquareXPos = 0;
    redSquareYPos = 0;
   
    // Charger un groupe d'images
    // 0001.jpg, 0002, jpg 
    for (counter = 1; counter < 10; counter += 1) {
        myImagesList.push("../images/water/v2/000" + counter + ".jpg");
    }

    // Charger un groupe d'images
    // 0010.jpg, 0011.jpg, 0012.jpg, 0013.jpg
    for (counter = 10; counter <= 30; counter += 1) {
        myImagesList.push("../images/water/v2/00" + counter + ".jpg");
    }


    preloadImagesCallback = function (imageIndex, img) {
        myImagesLoaded[imageIndex.toString()] = img;

        if (myImagesLoaded.length === 30) {
            // Loading complete
            renderingLoop(0);
        }

    };

    bindEvents = function () {
        $("#testbutton").bind('click', function () {
            redSquareXPos += 18.0;
            redSquareYPos -= 24.0;
        });

        var canvas = document.getElementById('canvas');
        
        canvas.onclick = function (evt) {
            var top, left, mouseX, mouseY, xPos, yPos, rawX, rawY;
    
            top = 0;
            left = 0;
            
            mouseX = evt.clientX - left + window.pageXOffset;
            mouseY = evt.clientY - top + window.pageYOffset;

            rawX = parseInt((mouseX - 6) / 18, 10);
            rawY = 30 - parseInt(mouseY / 24, 10);

            redSquareXPos = rawX * 18;
            redSquareYPos = rawY * 24 * -1;
        };
    };

    preloadImages = function () {
        
        var img, counter = 0;

        imgFront = new Image();
        imgFront.src = myMovingElement[0];

        imgGrid = new Image();
        imgGrid.src = myGrid[0];

        imgRedSquare = new Image();
        imgRedSquare.src = myRedSquare[0];

        

        for (counter = 1; counter <= myImagesList.length; counter += 1) {
            img = new Image();
            img.onload = preloadImagesCallback(counter - 1, img);
            img.src = myImagesList[counter - 1];
        }
    };
    renderingLoop = function (imageIndex) {

        var canvas = document.getElementById('canvas'), ctx, img,
            newIndex, testGridImage;
        ctx = canvas.getContext('2d');
        //ctx.globalAlpha = 0;
        
        
        img = myImagesLoaded[imageIndex];

        try {
            // Dessiner le plan d'eau
            ctx.drawImage(img, 0, 0);
            // Dessiner la grille blanche
            ctx.drawImage(imgGrid, 0, 0);
            // Dessiner les carrés rouges
            ctx.drawImage(imgRedSquare, redSquareXPos, redSquareYPos);
            // Dessiner un bateau
            ctx.drawImage(imgFront, 500, boatYPosition);
        } catch (exception) {
        };

        // Faire avancer le bateau
        boatYPosition -= 1;

        newIndex = (imageIndex + 1) % (myImagesLoaded.length - 1);
        setTimeout('FORCEBRUTE.RenderingLoop(' + newIndex + ')', 50);
    };

    return {
        RenderImages: function () {
            preloadImages();
        },
        RenderingLoop: renderingLoop,
        BindEvents: bindEvents
    };
}());




