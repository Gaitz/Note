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

    scrollToCurrentPageLink();

    function scrollToCurrentPageLink () {
      let pageURL = document.URL;
      if (/\/$/.test(pageURL) || /index.html$/.test(pageURL)) {
        navigatorMap.scrollTo(0, 0);
      }
      else {
        pageURL = "..".concat(pageURL.split('content')[1]);
        const thisPageNavElement = document.querySelector(`a[href='${pageURL}']`);
        thisPageNavElement.classList.add("currentPageLink");
        navigatorMap.scrollTo(0, thisPageNavElement.offsetTop - 60);
      }
    }
  }

  function handleLightBoxClick () {
    const navigatorMap = document.getElementById("js-lightBoxContainer");
    toggleStyle(navigatorMap, "hide");
    toggleStyle(document.getElementsByTagName("body")[0], "overflow-hide");
  }


  /* main process */
  const navigatorButton = document.getElementById("js-navigatorButton");
  navigatorButton.onclick = handleNavigatorButton;

  const lightBoxContainer = document.getElementById("js-lightBoxContainer");
  lightBoxContainer.onclick = handleLightBoxClick;
})();