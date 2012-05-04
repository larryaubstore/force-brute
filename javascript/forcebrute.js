/*global clearInterval: false, clearTimeout: false, document: false, event: false, frames: false, history: false, Image: false, location: false, name: false, navigator: false, Option: false, parent: false, screen: false, setInterval: false, setTimeout: false, window: false, XMLHttpRequest: false, $: false, alert: false */


var testFct, drawMyImageFct;

var FORCEBRUTE = (function () {
    "use strict";

    var myImagesList = ["../images/water/0001.jpg",
            "../images/water/0002.jpg",
            "../images/water/0003.jpg",
            "../images/water/0004.jpg",
            "../images/water/0005.jpg",
            "../images/water/0006.jpg",
            "../images/water/0007.jpg",
            "../images/water/0008.jpg",
            "../images/water/0009.jpg",
            "../images/water/0010.jpg",
            "../images/water/0011.jpg",
            "../images/water/0012.jpg",
            "../images/water/0013.jpg",
            "../images/water/0014.jpg",
            "../images/water/0015.jpg",
            "../images/water/0016.jpg",
            "../images/water/0017.jpg",
            "../images/water/0018.jpg",
            "../images/water/0019.jpg",
            "../images/water/0020.jpg",
            "../images/water/0021.jpg",
            "../images/water/0022.jpg",
            "../images/water/0023.jpg",
            "../images/water/0024.jpg",
            "../images/water/0025.jpg",
            "../images/water/0026.jpg",
            "../images/water/0027.jpg",
            "../images/water/0028.jpg",
            "../images/water/0029.jpg" ];

    drawMyImageFct = function (imageIndex) {
        var canvas = document.getElementById('canvas'), ctx, img, newIndex;
        ctx = canvas.getContext('2d');

        img = new Image();
        img.src = myImagesList[imageIndex];
        ctx.drawImage(img, 0, 0);
        newIndex = (imageIndex + 1) % myImagesList.length;
        setTimeout('drawMyImageFct(' + newIndex + ')', 50);
    };

    return {
        RenderImages: function () {
            drawMyImageFct(0);
        }
    };

    
}());




