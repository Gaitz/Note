(function () {
  'use strict'

  function toggleStyle (element , styleClass) {
    if (element.classList.contains( styleClass )) {
      element.classList.remove(styleClass);
    } else {
      element.classList.add(styleClass);
    }
  }

  function handleNavigatorButton () {
    const navigatorMap = document.getElementById("js-lightBoxContainer");
    toggleStyle(navigatorMap, "hide");
    toggleStyle(document.getElementsByTagName("body")[0], "overflow-hide");
  }

  function handleLightBoxClick () {
    const navigatorMap = document.getElementById("js-lightBoxContainer");
    toggleStyle(navigatorMap, "hide");
    toggleStyle(document.getElementsByTagName("body")[0], "overflow-hide");
  }

  function handleLightBoxScroll (event) {
    
  }

  /* main process */
  const navigatorButton = document.getElementById("js-navigatorButton");
  navigatorButton.onclick = handleNavigatorButton;

  const lightBoxContainer = document.getElementById("js-lightBoxContainer");
  lightBoxContainer.onclick = handleLightBoxClick;
  lightBoxContainer.onscroll = handleLightBoxScroll;
})();