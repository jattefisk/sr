var imgStep = 1;

function imgSlider () {

document.write("<h2>function imgSlider</h2>");

    if (!document.images) {
        return;
    }

    document.write("imgStep: " + imgStep);

    if (document.images.slider) {
        document.images.slider.src = eval("img" + imgStep + ".src");
    } else {
        document.write("UNDEFINDED: document.images.slider<br/>");
    }

    if (imgStep < 5) {
        imgStep++;
    } else {
        imgStep = 1;
    }

    setTimeout("imgSlider()", 2000);
}
