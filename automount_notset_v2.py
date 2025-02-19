from kubernetes import client, config

def list_pods_without_automount_token():
    # Load the in-cluster config or the default kubeconfig
    try:
        config.load_incluster_config()
    except config.ConfigException:
        config.load_kube_config()
    
    v1 = client.CoreV1Api()
    
    pods = v1.list_pod_for_all_namespaces(watch=False)
    
    print("Pods where automountServiceAccountToken is not set:")
    for pod in pods.items:
        if pod.spec.service_account_name == "default" and pod.spec.automount_service_account_token is None:
            print(f"Namespace: {pod.metadata.namespace}, Pod: {pod.metadata.name}")

if __name__ == "__main__":
    list_pods_without_automount_token()