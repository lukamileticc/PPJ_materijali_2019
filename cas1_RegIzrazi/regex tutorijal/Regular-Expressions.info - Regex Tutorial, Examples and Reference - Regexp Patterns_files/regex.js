function movecontent() {
  winW = document.documentElement.clientWidth;
  var side = document.getElementById("side");
  var bodytext = document.getElementById("bodytext");
  var tableflavor = document.getElementById("tableflavor");
  if (tableflavor) {
    if (side) {
      side.style.left = '0';
    }
    if (bodytext) {
      bodytext.style.left = '275px';
      if (winW < 10 + 250 + 10 + 748) {
        bodytext.style.width = (winW - 275) + 'px';
      } else {
        bodytext.style.width = '748px';
      }
    }
    tableflavor.style.width = (winW - 295) + 'px';
  } else {
    // 10 left margin; 275 side width including center margin; 10 extra center margin; 748 body text
    if (winW < 10 + 275 + 10 + 748) {
      if (side) {
        side.style.left = '0';
      }
      if (bodytext) {
        bodytext.style.left = '275px';
        bodytext.style.width = (winW - 275) + 'px';
      }
    } else {
      var margin = Math.floor((winW - 10 - 275 - 10 - 748) / 2);
      if (side) {
        side.style.left = margin + 'px';
      }
      if (bodytext) {
        bodytext.style.left = (margin + 275 + 10) + 'px';
        bodytext.style.width = '748px';
      }
    }
  }
}